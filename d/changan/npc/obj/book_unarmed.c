//book_unarmed.c

inherit ITEM;

void create() {
    set_name("〖拳法簡介〗", ({"unarmed book", "book"}));
    set_weight(600);
    set("unit", "本");
    set("long", "〖拳法簡介〗\n");
    set("value", 1000);
    set("material", "paper");
    set("skill", ([
        "name": "unarmed",
        "exp_required": 100,
        "sen_cost": 20,
        "difficulty": 20,
        "max_skill": 20
        ]));
}
