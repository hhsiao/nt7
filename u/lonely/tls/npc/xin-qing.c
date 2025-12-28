inherit NPC;
string ask_me();
void create()
{
	set_name("心清比丘", ({ "xinqing biqiu","xingqing","biqiu"}) );
	set("long","這是個年輕小夥子，看起來憨厚老實，老是微笑著。\n");
	set("gender", "男性" );
	set("attitude", "friendly");
	set("class", "bonze");
	set("age", 25);
	set("shen_type", 1);

	set("str", 23);
	set("int", 22);
	set("con", 24);
	set("dex", 24);
	create_family("天龍寺", 15, "弟子");
	set("inquiry",([
                "敲鐘" : (: ask_me :),
                "小小胖" : "小小胖真胖！",
        ]));

        set("qi", 600);
        set("max_qi", 600);
        set("jing", 500);
        set("eff_jingli", 500);
        set("max_jing", 500);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 20);
        set("combat_exp", 200000);
        set("score", 10);

        set_skill("strike", 60);
        set_skill("force", 60);
        set_skill("qiantian-yiyang", 70);
        set_skill("dodge", 60);
        set_skill("qingyan-zhang", 70);
        set_skill("tianlong-xiang", 70);
        set_skill("parry", 70);
        set_skill("buddhism", 60);
        set_skill("literate", 60);
        map_skill("strike", "qingyan-zhang");
        map_skill("force", "qiantian-yiyang");
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "qingyan-zhang");
        prepare_skill("strike","qingyan-zhang");

        set("hammer_count", 1);  
        set("chat_chance", 3);
	set("chat_msg", ({
		"心清道：又要敲鐘了，呵呵！\n",
	})); 
	setup();
	carry_object("/d/tls/obj/jiasha1")->wear();
	carry_object("/d/tls/obj/sengxie")->wear();
}

string ask_me()
{
	mapping fam = this_player()->query("family");
	mixed *local;
	object ob;
	local = localtime(time() * 60);

	if(!fam || fam["family_name"] != "天龍寺")
		return RANK_D->query_respect(this_player())+"與本寺素無來往，不知此話從何談起？";

	if(this_player()->query_skill("force",1) < 30)
		return "你的內功修為太差，敲鐘對你而言會傷害身體";

	if (local[2] < 6 || local[2] >= 21) 
		return "現在是休息時間了，你想吵死大家嗎？";

	if(query("hammer_count") < 1)
		return "你來晚了，已經有人在敲鐘了。";

	add("hammer_count", -1);
	ob = new("/d/tls/obj/zhongchui");
	ob->move(this_player());
	return "好吧，你拿著這個鍾槌去敲鐘吧。";
}

void reset()
{
	this_object()->set("hammer_count", 1);
}
