inherit ITEM;
inherit F_LIQUID;

void create() {
    set_name("醉仙茶", ({ "zuixian cha", "cha" }));
    set_weight(1000);
    set("long",
        "這是一杯顏色碧綠、香味濃郁上等好茶。是招待桃花島來客的。!\n");
    set("unit", "杯");
    set("value", 20);
    set("max_liquid", 10);
    set("liquid", ([
        "name": "醉仙茶",
        "remaining": 8,
        "type": "water"
        ]) );
    set("liquid_type", "water");
    setup();
}
