// /d/dali/npc/dizi-f.c
// By jpei
//update bye cool

inherit NPC;

void create()
{
    int name_no = random(2); 
	string *name_string = ({"閃電","小小胖"});

	set_name("女弟子", ({"nv dizi", "nv", "dizi"}) );
	set("long", "她正在專心致志地練習功夫。\n");
	set("gender", "女性" );
	set("age", 23);
	set("attitude", "peaceful");
	set("str",18);
	set("int",28);
	set("con",19);
	set("dex",22);
	set("max_qi", 650);
	set("max_jing", 250);
	set("neili", 500);
	set("max_neili", 320);
	set("jiali", 10);
	set("combat_exp", 15000);

	set_skill("force", 30);
	set_skill("qiantian-yiyang", 27);
	set_skill("dodge", 30);
	set_skill("tianlong-xiang", 28);
	set_skill("parry", 32);
	set_skill("cuff", 32);
	set_skill("duanjia-quan", 30);
	set_skill("sword", 30);
	set_skill("literate", 35);

	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "yiyang-zhi");
	map_skill("cuff", "duanjia-quan");
	map_skill("force", "qiantian-yiyang");
	prepare_skill("cuff","duanjia-quan");

	set("shen_type", 0);
	create_family("天龍寺", 16, "弟子");

	set("inquiry", ([
		"name": "奴家叫做" + name_string[name_no] + "，從小被寺裡的師傅收養。",
		"寒雨": "說起來也是他創造了我，不過這傢伙是個造ｑｕｅｓｔ狂。",
		"jpei": "說起來也是他創造了我，不過這傢伙是個造ｑｕｅｓｔ狂。",
	]) );

	setup();

	carry_object("/clone/misc/cloth.c")->wear();
}
