// honghua.c
inherit ITEM;

void create()
{
        set_name("無憂紅花", ({ "wuyou honghua" , "honghua" }) );
        set_weight(5);
        set_max_encumbrance(80);
        set("unit", "朵");
                set("prep", "on");
                set("long", "一朵鮮紅的花。\n");
                set("value", 1);
}
