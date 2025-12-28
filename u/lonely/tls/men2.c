inherit ROOM;
void create()
{
        set("short", "翔鶴門");
        set("long",@LONG
由光佛殿出此門，可向西行過無住寶塔、三元宮、兜率大士院。
這一路房屋都是寺中僧人清修養之地，你悄聲行走，不敢發出絲毫聲
響。北面通向無我閣。
LONG);
	set("outdoors","天龍寺");
        set("exits", ([
		"north" : __DIR__"wuwoge",
                "west": __DIR__"yz5",
                "east": __DIR__"gfd",
	]));
        set("coor/x",-360);
  set("coor/y",-320);
   set("coor/z",20);
   setup();
}
int valid_leave(object me, string dir)
{
        if (me->query("gender") == "女性" && dir =="north")
           return notify_fail("無我閣乃是王侯們進香還願時的休息之處，你一介女子要進去恐怕不太好吧？\n");
        return ::valid_leave(me, dir);
}


