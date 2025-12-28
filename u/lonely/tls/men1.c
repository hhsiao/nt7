inherit ROOM;
void create()
{
        set("short", "瑞鶴門");
        set("long",@LONG
由光佛殿出此門，可向東行過無相寶塔、幌天門、清都瑤臺、無
無境、雨花院而至般若臺。這一路房屋都是寺中僧人清修養之地，你
悄聲行走，不敢發出絲毫聲響。北面通向無淨閣。
LONG);
	set("outdoors","天龍寺");
        set("exits", ([
             "north" : __DIR__"wujingge",
	       "west": __DIR__"gfd",
	       "east": __DIR__"yz4",
	]));
        set("coor/x",-340);
  set("coor/y",-320);
   set("coor/z",30);
   setup();
}
int valid_leave(object me, string dir)
{
        if (me->query("gender") != "女性" && dir =="north")
           return notify_fail("無淨閣乃是王侯夫人小姐們進香還願時的休息之處，你要進去恐怕不太好吧？\n");
        return ::valid_leave(me, dir);
}
