//Cracked by Kafei
// ni.c 泥

inherit ITEM;

void create()
{
        set_name("溼泥", ({"shi ni", "mud"}));
        set_weight(1000);
        set("long", "一團從西湖挖來的溼泥。\n");
                set("unit", "團");
                set("value", 0);

        setup();
}
