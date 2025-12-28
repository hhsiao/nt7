// taijie.c
// bbb 1997/07/20
// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "臺階");
	set("long", @LONG
一條臺階斜向上引，走到一百多級時，隱隱聽到轟隆轟隆的水聲，又行二
百餘級，水聲已經震耳欲聾，前面並有光亮透入，走到臺階的盡頭，前面是個
僅可容身的洞穴。
LONG
	);

	set("exits", ([
            "down" : __DIR__"dong1",
            "out" : __DIR__"jiangpan",
	]));
	setup();
}