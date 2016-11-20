let jnet = require('./json_net');

let client = jnet.JSONSocket();

var test_com = function(port, host) {

  let status = false;
  let i = 0;
  let input = [{ "command": "put", "key": "key1", "value": 14, "timestamp": 0 },
    { "command": "put", "key": "key2", "value": 15, "timestamp": 0 }];

  client.on('connect', function() { status = true; console.log("Connected to server."); });
  client.setTimeout(5000);// If no response, assume port is not listening
  client.on('timeout', function() { status = 'closed'; client.destroy(); });
  client.on('error', function(exception) { status = 'closed'; });
  client.on('close', function(exception) { console.log("Connection closed."); });
  client.connect(port, host);

  setTimeout(function() {
    if(true == status) {
      client.jwrite({"command":"ee590"},inputVals);
    };
  }, 1000);
  function inputVals() {
    setTimeout(function() {
      let UNIXTIME = Math.floor(new Date() / 1000);
      if(i < input.length) {
        input[i].timestamp = UNIXTIME;
        client.jwrite(input[i++], inputVals);
      } else {
        console.log("Finished testing.");
        client.end();
      }
    }, 1000);
  };
};
client.on('json', function(object) {
  console.log(object);
});

var LAN = process.argv[2];   //Address to connect
var PORT = 8080;         //data_server.js port

test_com(PORT, LAN);
