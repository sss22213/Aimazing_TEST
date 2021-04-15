# Aimazing test

## Test Environment:
 - Distributor ID:	Ubuntu
 - Description:	Ubuntu 20.04.2 LTS
 - Release:	20.04
 - Codename:	focal

## Compile sniffing:
```bash=
cd Aimazing_TEST
make
```
---

### Test sniffing:
```bash=
bash scripts/test.sh <NETWORK INTERFACE> <FILENAME_FOR_RECORD>
```
ex:
```bash=
bash scripts/test.sh "ens33" log.bin
```
---

### Test replace:
```bash=
bash scripts/test.sh <FILE PATH> <STRING1> <STRING2>
```

ex: hello world helloworld => hi world hiworld (hello->hi)
```bash=
bash scripts/replace.sh demo_file/test.txt hello hi
```

