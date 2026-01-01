// lazhu.c
inherit ITEM;

void create()
{
        set_name( "蠟燭", ({ "zhu", "lazhu" }) );
        set_weight(10);
        set("unit", "只");
                set("long", "這是一隻普通的蠟燭，上面鏤著一些花紋，還比較精緻。\n");
                set("value", 0);
        setup();
}
void init()
{
        call_out("dest", 1800);
}
void dest()
{
        write("眼前燭光一閃，不好，蠟燭熄滅了。\n");
        destruct(this_object());
}
