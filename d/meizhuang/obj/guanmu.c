// guanmu.c
inherit ITEM;

void create()
{
        set_name("灌木", ({ "guanmu" , "灌木"}) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        set("unit", "叢");
                set("long", "這是一叢不知名的灌木，生長得很茂盛。\n");
                set("value", 1);
}
