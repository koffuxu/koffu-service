# Overview

This is binder test module after I read binder many times

# Intor

- KfService as service
- test-kfservice as client
- doc is some draft document
- log show
in kfservice proc
```
binder proc state:
proc 5712
line1#  thread 5712: l 12
line2# thread 5713: l 12
line3# node 27489: u00000000f72de070 c00000000f72ce064 hs 1 hw 1 ls 0 lw 0 is 1 iw 1 proc desc99:3300
line4# ref 27487: desc 0 refPid:3300 node 1 s 1 w 1 d           (null)
```

in servicemanager proc
```
binder proc state:
proc 3300
line1# thread 3300: l 12
line2# node 1: u0000000000000000 c0000000000000000 hs 1 hw 1 ls 1 lw 1 is 52 iw 52 proc ... desc0:571
...
line3# ref 27490: desc 99 refPid:5712 node 27489 s 1 w 0 d ffffffc049f07e00
```

# create in init.rc

```
+service bbt_manager /system/bin/bbtmanager
+    class main
+    user root
+    group root

```
