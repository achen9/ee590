let jnet = require('./json_net');
let Clients = require("./clients")

let server = new jnet.JSONServer();

server.clients = new Clients();

server.on('json_connection',function(jsocket) {
  let acquainted = false;
  var responses = {
    ee590: function(object) {
      acquainted = true;
      jsocket.jwrite({result: "ok"});
    },

    push: function(object) {
      if(acquainted) {
        server.clients.push(object.value);
        jsocket.jwrite({ value: object.value });
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

});

server.on('error', (err) => {
  throw err;
});

server.listen(8080, () => {
  console.log('server bound');
});
