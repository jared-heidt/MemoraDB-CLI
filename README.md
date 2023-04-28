# MemoraDB Command Line Interface
## User Commands
### Name
memora - manage key value pairs in connected MemoraDB

### Usage
memora [COMMAND] [KEY] [VALUE]

### Commands 
connect - connect to MemoraDB
close - close connection to MemoraDB
exit - exit cli
create - create a key value pair
read - list key value pairs
update - update the value of an existing key
delete - remove existing key value pair
upsert - insert if key does note exist, update if key exists

### Examples
Create the key value pair (challenger, 1)
```bash
$ ./memora -c challenger 1
```

Read the key value pair with key challenger
```bash
$ ./memora -r challenger
```

Update the key value pair with key challenger
Create the key value pair (challenger, 1)
```bash
$ ./memora -u challenger 14
```

Delete the key value pair with key challenger
Create the key value pair (challenger, 1)
```bash
$ ./memora -d challenger
```

## References
- https://github.com/dmulholl/kash/tree/master
- https://clig.dev/#the-basics