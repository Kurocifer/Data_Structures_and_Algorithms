/* A chaining solution to collissions in hash */
struct hash_node {
    int data;               /*The data we need to store */
    char key[MAX_KEY];      /* The key for this record */
    struct hash_node *next; /* ptr to next node in chain */
};

struct hash_node *hash_table[ HASH_SIZE];

struct hash_node *get_hash(char *key)
{
    int slot;
    struct hash_node *first_elem;

    slot = hash_function(key);
    first_elem = hash_table[slot];
    return(mod_seq_srch(first_elem, key));
}

void ins_hash(struct hash_node *new_elem)
{
    int slot;

    slot = hash_function(new_elem->key);
    new_elem->next = hash_table[slot];
    hash_table[slot] = new_elem;
}