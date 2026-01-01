// yufo.c

inherit ITEM;

void create()
{
        set_name("玉佛", ({ "yu fo", "fo" }));
        set_weight(1000);
        set("unit", "個");
                set("no_sell", "這...這是什麼東西？我可不敢要。\n");
                set("long", "這是一尊笑眯眯的彌勒佛。\n");
                set("value", 1);
                set("material", "jade");
        setup();
}
