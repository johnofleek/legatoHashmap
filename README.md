## Legato hashmap

An attempt to understand it


# Legato Command line build

From project root  

**Set the cross build environment**  

source ~/legato/packages/legato.sdk.latest/resources/configlegatoenv

***Due to broken legato-spm - grrr*** 
source ~/legato/packages/legato.sdk.16.10.4.wp85-wp75-native-x86_64-201712131538/resources/configlegatoenv

**Build for wp85**  

```
make wp85
```


** install from host (assumes target is 192.168.2.2)**  

```
make install 
```




# GIT  

## Git clone the project  

```
git clone https://github.com/johnofleek/legatoHashmap.git
```


## Git "checkin"

```
git add .
git commit -m "your comment"
git push -u origin master
```

## Git "checkout"

```
git pull origin master
```


