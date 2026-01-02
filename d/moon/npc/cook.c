// butcher.c

inherit NPC;

void create() {
    set_name("廚師", ({ "cook" }) );
    set("gender", "男性" );
    set("age", 35);
    set("long", "一個山莊的廚子， 正在忙呢。\n");
    set("str", 29);
    set("int", 14);
    set("combat_exp", 25000);
    set("attitude", "heroism");
    set_skill("dagger", 100);
    set_skill("parry", 100);
    set_skill("dodge", 150);
    setup();
    add_money("silver", 50);
    /*
     * carry_object("/obj/cloth")->wear();
     * carry_object( __DIR__ "obj/badblade")->wield();
     */
}

void init() {
    object ob;

    ::init();
    if(interactive(ob = this_player()) && !is_fighting() ) {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}

void greeting(object ob) {
    if(!ob || environment(ob) != environment() ) return;
    switch(random(2) ) {
    case 0:
        say("廚子擦了擦頭上的汗。”\n");
        break;
    case 1:
        say("廚師道：“真累呀。\n");
        break;
    }
}
