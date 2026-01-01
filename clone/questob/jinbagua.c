// jinbagua.c

inherit ITEM;

void create()
{
        set_name("金八卦", ({ "jin bagua", "bagua" }));
        set_weight(1200);
        set("unit", "面");
                set("no_sell", "這...這是什麼東西？我可不敢要。\n");
                set("long", "一面純金襯底嵌玉的八卦，非常華貴。\n");
                set("value", 1);
                set("material", "gold");
        setup();
}
