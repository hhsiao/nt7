#include <ansi.h>
inherit NPC;
void create() {
    set_name("柳若松", ({ "liu" }) );
    set("gender", "男性");
    set("title", HIG"青松"NOR);
    set("combat_exp", 500000);
    set("age", 32);
    set("max_atman", 300);
    set("atman", 300);
    set("env/wimpy", 90);
    set("long",
        "此人原系武當門下，江湖上頗有俠名，因沉溺名利，施計陷害丁鵬，
        被丁鵬揭穿其假面後竟忍辱拜丁鵬為師，意圖東山再起。\n"
    );
    set_skill("sword", 100);
    set_skill("move", 120);
    set_skill("parry", 100);
    set_skill("dodge", 50);
    set_skill("unarmed", 50);
    set("inquiry", ([
        "圓月山莊" : "我告訴你圓月山莊的秘密，你可有好處給我？不如讓我看看先。(show)",
        "秘密" : "我告訴你圓月山莊的秘密，你可有好處給我？不如讓我看看先。(show)", ]) );
    set("chat_chance", 5);
    set("chat_msg", ({
        name() + "神秘的說道：圓月山莊的秘密.......\n",
        name() + "道：我心裡在打什麼主意，用不著等我說出來，你也能猜得到的。\n"
    }) );
    setup();
    carry_object("/obj/cloth")->wear();
    carry_object(__DIR__ "obj/sword")->wield();
}

void init() {
    ::init();
    add_action("do_show", "show");
}

int do_show(string arg)
{     object mygold, room, me;
    me = this_player();
    mygold = present("gold_money", this_player());
    if(!mygold) return notify_fail("柳若松乾咳兩聲道：這年頭，只有真金白銀才靠得住呀。\n");
    message_vision("\n\n$N衝著柳若松輕輕地掂了掂手中的黃金...\n", me);
    if((int)mygold->query_amount() < 50)
        return notify_fail("\n\n柳若松滿臉正色地說道：這麼點金子就想套出我的秘密嗎？！\n");
    message_vision("\n\n柳若松一把抓過黃金，滿臉堆笑對$N道：山莊內室裡有條密道，請跟我來。\n", me);
    mygold->add_amount(-50);
    room = find_object("n/moon/nroom");
    if(!objectp(room)) room = load_object("u/moon/nroom");
    message_vision(HIY"\n\n柳若松帶著$N匆匆忙忙向山莊內室走去....\n\n"NOR, me);
    me->move(room);
    destruct(this_object());
}
