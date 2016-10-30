#include "hash.hh"
#include "null.hh"
#include "string.hh"

Hash::Hash(void) {

  for ( int i=0; i<num_shelves; i++ ) {
    shelves[i] = NULL;
  }

}

Hash::Hash ( const Hash &hash ) {
  Array k;
  for ( int i=0; i<num_shelves; i++ ) {
    shelves[i] = NULL;
  }
  k = hash.keys();
  for (int i = 0; i < k.length(); i++) {
    std::string key = k.get(i)->get_str();
    set(key, *hash.get(key));
  }
}

Hash::~Hash(void) {
  for (int i = 0; i < num_shelves; i++) {
    while (shelves[i] != NULL) {
      Bucket *tmp_next;
      tmp_next = shelves[i]->next;
      delete shelves[i];
      shelves[i] = tmp_next;
    }
  }
}

void Hash::set ( std::string key, Object &value ) {

  // TODO: Homework: Use delete if key exists to avoid duplicate keys
  //       or reset the value in place (make sure to delete old value!)

  int i = hash(key);

  Bucket * ptr = new Bucket;

  ptr->key = key;
  ptr->value = value.clone();
  ptr->next = shelves[i];
  shelves[i] = ptr;

}

Object * Hash::get ( std::string key ) const {

  //DEBUG("getting " + key);

  int i = hash(key);

  Bucket * ptr = shelves[i];

  //DEBUG("1");

  while ( ptr && ptr->key != key ) {
    ptr = ptr->next;
  }

  //DEBUG("2");

  if ( ptr ) {
    //DEBUG("3");
    return ptr->value;
  } else {
    //DEBUG("4");
    throw Object_Exception("No value for key.");
  }

}

int Hash::hash (std::string s ) const {

  int n = 0;

  for ( int i=0; i < (int)s.length(); i++ ) {
    n += (int) s[i];
  }

  return n % num_shelves;

}

std::string Hash::stringify(void) {

  std::string s = "{";

  for ( int i=0; i<num_shelves; i++ ) {
    Bucket * ptr = shelves[i];
    while ( ptr != NULL ) {
      s += "\"" + ptr->key + "\"" + ":" + ptr->value->stringify() + ",";
      ptr = ptr->next;
    }
  }

  if ( s[s.length()-1] == ',' ) {
    s[s.length()-1] = '}';
  } else {
    s += "}";
  }

  return s;

}

Array Hash::keys(void) const {
  Array k;
  int key_index = 0;
  Bucket *next_bucket;
  for (int i = 0; i < num_shelves; i++) {
    next_bucket = shelves[i];
    while (NULL != next_bucket) {
      String str(next_bucket->key);
      k.set(key_index, str);
      key_index++;
      next_bucket = next_bucket->next;
    }
  }
  return k;
}
