// letter.c
inherit ITEM;

void create()
{
        set_name("手信", ({"hand letter"}));
        set_weight(100);
        set("unit", "封");
                set("long",
"這是華山派掌門岳不群的手信，請馮鐵匠把打好的寶劍交給執信弟子。\n");
                set("material", "paper");
}
