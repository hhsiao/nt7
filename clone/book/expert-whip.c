// expert_whip.c

inherit BOOK;

void create() {
    set_name("鞭法秘要", ({ "whip book", "book" }));
    set_weight(600);
    set("unit", "本");
    set("long",
        "封面上寫著「鞭法秘要）」\n");
    set("value", 50000);
    set("material", "paper");
    set("skill", ([
        "name": "whip",
        "exp_required": 1000,
        "jing_cost": 50,
        "difficulty": 30,
        "max_skill": 99,
        "min_skill": 50
        ]));
}
