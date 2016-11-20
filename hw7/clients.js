let JSONable = (superclass) => class extends superclass {
  stringify() {
    return JSON.stringify(this);
  }
};

class Clients extends JSONable(Object) {

  constructor() {
    super();
  }
}

module.exports = Clients;
