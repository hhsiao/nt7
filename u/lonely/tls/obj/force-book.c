
inherit ITEM;

void create()
{
	set_name("線裝經書", ({ "jingshu", "shu", "jing", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "這是一本很舊的線裝經書。封面寫著四句偈語：有常無常 雙樹枯榮 南北西東 非假非空 \n");
    	set("value", 0);
		set("material", "paper");
	
	}
}
void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}
int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int jylevel; 
        int neili_lost;
        if (!(arg=="jing" ||arg=="book"))
        return 0;

        if (where->query("pigging")){
                write("你還是專心拱豬吧！\n");
                return 1;
        }
        if (me->is_busy()) {
                write("你現在正忙著呢。\n");
                return 1;
        }

        if( me->is_fighting() ) {
                write("你無法在戰鬥中專心下來研讀新知！\n");
                return 1;
        }

        if (!id(arg)) {	
                write("你要讀什麼？\n");
                return 1;
        }
       
        if( !me->query_skill("literate", 1) ){
                write("你是個文盲，先學點文化(literate)吧。\n");
                return 1;
        }
        
        if( (int)me->query("jing") < 15 ) {
                write("你現在過於疲倦，無法專心下來研讀新知。\n");
                return 1;
        }
	if (me->query_skill("force",1)<80){
		write("你的內功基礎沒有打好，不能修練枯榮禪功。\n");
		return 1;
	}
       if (me->query_skill("qiantian-yiyang",1)<80){
		write("由於你的乾天一陽功不夠火候，不能學習枯榮禪功。\n");
		return 1;
	}

	if (me->query_skill("qiantian-yiyang",1)<me->query_skill("kurong-changong",1)){
		write("由於你的乾天一陽功不夠嫻熟，不能再繼續學習枯榮禪功。\n");
		return 1;
	}
	if( (int)me->query("neili") < neili_lost) {
		write("你內力不夠，無法鑽研這麼高深的武功。\n");
                return 1;
        }
	if ((int)me->query_skill("buddhism",1)<(int)me->query_skill("kurong-changong",1))
	{
		write("你的禪宗心法修為不夠，無法領會更高深的枯榮功。\n");
		return 1;
	}
        if(me->query_skill("kurong-changong",1)>40){
                write("你已經無法再從經書上領悟到什麼了。\n");
                return 1;
        }
	neili_lost=(int)(me->query_skill("kurong-changong",1)/10);
        me->receive_damage("jing", 15);
	me->set("neili",(int)me->query("neili")-neili_lost);
	me->improve_skill("kurong-changong", (int)me->query_skill("literate", 1)/3+1);
	message("vision", me->name() + "拿著一本經書正在默默唸著。\n", environment(me), me);
        write("你默誦經書，頗有心得。\n");
	return 1;
}
