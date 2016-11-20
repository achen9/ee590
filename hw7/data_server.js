let jnet = require('./json_net');
let Clients = require("./clients")

let server = new jnet.JSONServer();

server.clients = new Clients();

server.on('json_connection',function(jsocket) {
  let acquainted = false;
  let address = jsocket.address().address;
  console.log("Connected to: " + address);
  var responses = {
    ee590: function(object) {
      if(acquainted) {
        jsocket.jwrite("Already acquainted.");
      } else {
        acquainted = true;
        jsocket.jwrite({ result: "ok" });
      }
    },

    put: function(object) {
      if(acquainted) {
        if(!("key" in object)) {
          jsocket.error("No key provided.");
        } else if(!("value" in object)) {
          jsocket.error("No value provided.");
        } else if(!("timestamp" in object)) {
          jsocket.error("No timestamp provided.");
        } else {
          if("string" != typeof (object.key)) {
            jsocket.error("Key is not a string.");
          } else if("string" != typeof (object.value) && "number" != typeof (object.value) && "boolean" != typeof (object.value)) {
            jsocket.error("Value is not a string, number, or boolean.");
          } else if(object.timestamp < 0) {
            jsocket.error("Timestamp is negative.");
          } else {
            let UNIXTIME = Math.floor(new Date() / 1000);
            if(!(address in server.clients)) {
              server.clients[address] = {};
            }
            server.clients[address][object.key] = { value: object.value, timestamp: object.timestamp, received: UNIXTIME }
            jsocket.jwrite({result: server.clients[address][object.key]});
          }
        }
        } else {
        jsocket.error("Not yet acquainted");
      }
    },

    pop: function(object) {
      if(acquainted) {
        jsocket.jwrite({ value: server.clients.pop() });
      } else {
        jsocket.error("Not yet acquainted");
      }
    },

    top: function(object) {
      if(acquainted) {
        if(server.clients.length > 0) {
          jsocket.jwrite({ value: server.clients[server.clients.length - 1] });
        } else {
          jsocket.error("Empty stack during 'top'");
        }
      } else {
        jsocket.error("Not yet acquainted");
      }
    },

    end: function(object,socket) {
      jsocket.end();
    }

  }

  jsocket.on('json', function(object) {

    if ( responses[object.command] ) {
      responses[object.command](object);
    } else {
      jsocket.error("Unknown command '" + object.command + "'");
    }

    console.log(server.clients);

  });

  jsocket.on('close', function() {
    console.log("Closed connection to: " + address);
  });

});

server.on('error', (err) => {
  throw err;
});

server.listen(8080, () => {
  console.log('server bound');
});
