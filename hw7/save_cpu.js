let jnet = require('./json_net');

let client = jnet.JSONSocket();
let input_index = 0;
let commands = [
    { "command": "put", "key": "cpu load", "value": 0, "timestamp": 0 },
    { "command": "put", "key": "name", "value": "Alex Chen", "timestamp": 0 },
    { "command": "get" },
    { "command": "get", "key": "cpu load" },
    { "command": "get", "key": "cpu load", "host": client.address().address }];

var save_cpu_data = function(port, host) {
  let status = false;
  let total_cpu_time = 0;
  let user_cpu_time = 0;
  let cpu_load = 0;
  let cpu_data = require('os').cpus();
  for(let i = 0; i < cpu_data.length; i++) {
    total_cpu_time = total_cpu_time +
      cpu_data[i].times.user +
      cpu_data[i].times.nice +
      cpu_data[i].times.sys +
      cpu_data[i].times.idle +
      cpu_data[i].times.irq;
    user_cpu_time += cpu_data[i].times.user;
  };
  if(0 != total_cpu_time) {
    cpu_load = user_cpu_time / total_cpu_time;
    commands[0].value = cpu_load;
  } else {
    console.error("total_cpu_time is zero.");
  }
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
  if(2 > input_index) {
    let UNIXTIME = Math.floor(new Date() / 1000);
    commands[input_index].timestamp = UNIXTIME;
    client.jwrite(commands[input_index++]);
  } else if(input_index < commands.length) {
    if(2 == input_index) {
      console.log("Beginning get() function tests...");
    }
    client.jwrite(commands[input_index++]);
  } else {
    console.log("Finished testing all get() functions.");
    client.end();
  }
});

var LAN = process.argv[2];  //Address to connect
var PORT = process.argv[3]; //data_server.js port

save_cpu_data(PORT, LAN);
