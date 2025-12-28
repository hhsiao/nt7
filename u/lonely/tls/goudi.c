// /u/cool/tls/goudi.c
// 1997.2.13
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short","百丈橋底");
  set("long",@LONG
這裡是百丈橋底，四周都是大石。一條小河順流而下，四周有不
少骨骸，大概都是失足摔死的。這裡東面山坡上是一片松林，看來只
好從那邊上。
LONG);

     set("outdoors", "天龍寺");
     set("exits",([
           "eastup" : __DIR__"road5",
     ]));
     setup();
}
