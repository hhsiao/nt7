//cool 98.2.17

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("了明禪師", ({	"liaoming chanshi", "liaoming", "chanshi"}));
	set("long",
		"他是一位身材削瘦的中年僧人，兩臂不甚粗壯。身穿 \n"
              "一襲灰布鑲邊袈裟，兩眼湛湛有神，似乎有一身武藝。\n"
	);

	set("nickname", "他心尊者");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 45);
	set("str", 23);
	set("int", 23);
	set("con", 23);
	set("dex", 25);

	set("max_qi", 1400);
	set("max_jing", 1300);
	set("neili", 1800);
	set("max_neili", 1800);
	set("eff_jingli", 1000);
	set("jiali", 70);
	set("combat_exp", 800000);
	set("shen", 8000);

	set_skill("force", 100);
	set_skill("qiantian-yiyang", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("tianlong-xiang", 100);
	set_skill("finger", 100);
	set_skill("sword", 100);
	set_skill("strike", 100);
	set_skill("qingyan-zhang", 100);
	set_skill("yiyang-zhi", 100);
	set_skill("buddhism", 100);
	set_skill("literate", 90);
	map_skill("strike", "qingyan-zhang");
	map_skill("force", "qiantian-yiyang");
	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "yiyang-zhi");
	map_skill("finger",  "yiyang-zhi");
	prepare_skill("finger", "yiyang-zhi");
	create_family("天龍寺", 14, "弟子");    

	set("inquiry", ([
		"藥" :  "本寺靈丹妙藥不少，最有名的就是天龍丹和雪露丸",
	]));
	setup();
        carry_object("/d/tls/obj/jiasha1")->wear();
        carry_object("/d/tls/obj/sengxie")->wear();
}

#include "liao.h";
