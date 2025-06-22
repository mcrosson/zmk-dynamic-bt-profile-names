# ZMK Dynamic BT Profile Names

This repo implements dynamic bluetooth profile naming for zmk as a module.

## Usage

Please see the zmk docs about modules for how to add this module to your zmk builds.

## Building

``` sh
docker run --rm -it -v s:/src/zmk-ardux-kmn:/zmk-ardux-kmn zmkfirmware/zmk-build-arm:stable
cd /zmk-ardux-kmn
west init -l config
west update
west zephyr-export
west build -s zmk/app -b nice_nano_v2 -- -DSHIELD=the_paintbrush_left -DZMK_CONFIG="/zmk-ardux-kmn/config"
```

``` patch
diff --git a/.gitignore b/.gitignore
index 329f3e5..0f2e7e6 100644
--- a/.gitignore
+++ b/.gitignore
@@ -1 +1,7 @@
-.build/
\ No newline at end of file
+.build/
+build/
+.west/
+modules/
+zephyr/
+zmk-dynamic-bt-profile-names/
+zmk/
\ No newline at end of file
diff --git a/config/west.yml b/config/west.yml
index 1f5b42f..d22f99c 100644
--- a/config/west.yml
+++ b/config/west.yml
@@ -4,10 +4,15 @@ manifest:
       url-base: https://github.com/zmkfirmware
     - name: zmk-ardux
       url-base: https://github.com/arduxio
+    - name: zmkdynamicbtprofilenames
+      url-base: https://github.com/mcrosson
   projects:
     - name: zmk
       remote: zmkfirmware
       revision: 6b44d33db2f4bad7d98e475e6f7968493b05af73
       import: app/west.yml
+    - name: zmk-dynamic-bt-profile-names
+      remote: zmkdynamicbtprofilenames
+      revision: main
   self:
     path: config
```

## Licensing

Unless otherwise stated all source code is licensed under the [Apache 2 License](LICENSE-APACHE-2.0.txt).

Unless otherwise stated the non source code contents of this repository are licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](LICENSE-CC-Attribution-NonCommercial-ShareAlike-4.0-International.txt)