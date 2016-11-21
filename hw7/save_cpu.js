let jnet = require('./json_net');

let client = jnet.JSONSocket();

var save_cpu_data = function(port, host) {
  let status = false;
  let total_cpu_time = 0;
  let user_cpu_time = 0;
  let cpu_load = 0;
  let cpu_data = require('os').cpus();
  let stored_data = { "command": "put", "key": "cpu load", "value": 0, "timestamp": 0 };
  let input_index = 0;
  let get_inputs = [
    { "command": "get" },
    { "command": "get", "key": "cpu load" },
    { "command": "get", "key": "cpu load", "host": client.address().address }];
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
    stored_data.value = cpu_load;
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
      client.jwrite({"command":"ee590"},store_cpu_load);
    };
  }, 1000);
  function store_cpu_load() {
    setTimeout(function() {
      let UNIXTIME = Math.floor(new Date() / 1000);
      stored_data.timestamp = UNIXTIME;
      client.jwrite(stored_data, get_cpu_load);
    }, 1000);
  };
  function get_cpu_load() {
    setTimeout(function() {
      if(input_index < get_inputs.length) {
        client.jwrite(get_inputs[input_index++], get_cpu_load);
      } else {
        console.log("Finished testing all get functions.");
        client.end();
      }
    }, 1000);
  }
};
client.on('json', function(object) {
  console.log(object);
});

var LAN = process.argv[2];  //Address to connect
var PORT = process.argv[3]; //data_server.js port

save_cpu_data(PORT, LAN);
