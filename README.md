# Aimazing test

## Test Environment:
 - Distributor ID:	Ubuntu
 - Description:	Ubuntu 20.04.2 LTS
 - Release:	20.04
 - Codename:	focal

## Install dependent(libtins):

1. Create the build directory
```bash=
mkdir build
cd build
```

2. Configure the project. Add any relevant configuration flags
```bash=
cmake ../
```

3. Compile
```bash=
make
sudo make install
```
---

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

---

## Reference:

[libtins](http://libtins.github.io/)
