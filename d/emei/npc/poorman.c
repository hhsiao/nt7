// poorman.c

inherit NPC;

void create() {
    set_name("窮漢", ({ "poor man", "man" }) );
    set("gender", "男性" );
    set("age", 33);
    set("long", "一個骨瘦如柴，滿臉菜色的窮漢。\n");
    set("attitude", "friendly");
    set("combat_exp", 250);
    //      set("shen", 50);
    set("shen_type", 1);
    set("str", 20);
    set("dex", 18);
    set("con", 17);
    set("int", 13);
    setup();
    set("chat_chance", 15);
    set("chat_msg", ({
        "窮漢懶洋洋地打了個哈欠。\n",
        "窮漢懶洋洋地打了個哈欠道：這洞裡適合建築和潛伏隱修。\n",
        "窮漢懶洋洋地打了個哈欠道：劍俠，劍仙... 可惜，仙緣難求啊。\n",
        "窮漢伸手捉住了身上的蝨子，罵道：長眉老兒說這洞裡封著血神子，真他媽胡扯。 \n",
        (: random_move :)
    }) );
    carry_object("/d/emei/npc/obj/cloth")->wear();
}
