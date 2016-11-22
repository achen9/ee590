let jnet = require('./json_net');

let client = jnet.JSONSocket();
let i = 0;
let input = [
  { "command": "put" },
  { "command": "put", "key": "key1" },
  { "command": "put", "key": false, "value": 0.5 },
  { "command": "put", "key": false, "value": 0.5, "timestamp": 45 },
  { "command": "put", "key": "key1", "value": [1, 2, 3], "timestamp": 45 },
  { "command": "put", "key": "key1", "value": 0.5, "timestamp": false },
  { "command": "put", "key": "key1", "value": 0.5, "timestamp": -25 },
  { "command": "put", "key": "key1", "value": 14, "timestamp": 0 },
  { "command": "put", "key": "key2", "value": 15, "timestamp": 0 },
  { "command": "get" },
  { "command": "get", "key": "badkey" },
  { "command": "get", "key": "key1", "host": "badhost" },
  { "command": "get", "key": "key1" },
  { "command": "get", "key": "key1", "host": "::ffff:10.0.0.193" }];

var test_com = function(port, host) {

  let status = false;
  client.on('connect', function() { status = true; console.log("Connected to server."); });
  client.setTimeout(5000);// If no response, assume port is not listening
  client.on('timeout', function() { status = 'closed'; client.destroy(); });
  client.on('error', function(exception) { status = 'closed'; });
  client.on('close', function(exception) { console.log("Connection closed."); });
  client.connect(port, host);

  setTimeout(function() {
    if(true == status) {
      client.jwrite({"command":"ee590"});
    };
  }, 1000);
};
client.on('json', function(object) {
  console.log(object);
  let UNIXTIME = Math.floor(new Date() / 1000);
  if(9 > i && 6 < i) {
    input[i].timestamp = UNIXTIME;
    client.jwrite(input[i++]);
  } else if (i >= input.length) {
    console.log("Finished testing.");
    client.end();
  } else {
    client.jwrite(input[i++]);
  }
});

var LAN = process.argv[2]; //Address to connect
var PORT = 8080;           //data_server.js port

test_com(PORT, LAN);
