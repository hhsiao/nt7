// tiepai.c

inherit ITEM;

void create() {
    set_name("鐵牌", ({ "qulingfeng tiepai", "tiepai", "pai" }) );
    set("long", "一面做成八卦形狀的鐵牌，翻過來看，背面寫著一個“曲”字。");
    set_weight(10);
    set("unit", "面");
    setup();
}
