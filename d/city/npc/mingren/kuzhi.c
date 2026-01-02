#include <ansi.h>;
inherit NPC;

void create() {
    set_name(HIW "枯枝" NOR, ({ "kuzhi" }));
    set("title", HIR "夢想之神" NOR);
    set("gender", "男性");
    set("age", 36);
    set("no_get", 1);
    set("long", @LONG
“一旦讓我開始，我就不會停止，人不能沒有夢想！”
枯枝，夢想之神，騎車去過千島湖去過廈門去過海南去過青島，
2014年他的夢想是騎車到西藏，歷時一個月從昆明到西藏的朝聖之路，夢想實現了。
但沒有覺得騎車去西藏是什麼英雄壯舉，只是因為夢想的力量以及那最樸素的人、最清澈的水、最漂亮的星空、最神聖的雪山。
生命的意義就是不斷的前進，去到更高更遠。
泥潭7的夢想之神，夢想將繼續！
LONG );
    set("combat_exp", 60000);
    set("shen_type", 1);
    set("attitude", "friendly");

    set("apply/attack", 50);
    set("apply/defense", 50);

    set("max_qi", 800);
    set("max_jing", 800);
    set("max_neili", 800);

    setup();

    carry_object("/clone/misc/cloth")->wear();
    //carry_object("/clone/weapon/changjian")->wield();
    call_out("qima", 2);
}

int qima() {
    object ma;
    if (!objectp(environment())) {
        call_out("qima", 2);
        return 1;
    }
    ma = new("/clone/horse/baima.c");
    set("no_get", 1, ma);
    set("name", "自行車", ma);
    ma->move(environment());
    command("ride bai ma");
    return 1;
}
