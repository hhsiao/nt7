#include <ansi.h>
inherit NPC;
inherit "/d/war/diablo";
int do_task();
int ask_forge();
int do_cancel();
int is_vendor() { return 1; }
int legit_buyer(object me) { return 1; }

string *quest_fail_msg = ({
        CYN"看起來很是生氣，但似乎又發作不出來，只是輕輕哼了一聲。\n"NOR,
	CYN"冷哼一聲：“怎的你竟是如此不中用？！！”\n"NOR,
	CYN"對著你搖了搖頭，說：“連這點事都做不好.....下去吧。”\n"NOR,
	CYN"裡嘟囔著：“真是沒用。。。。”\n"NOR,
	CYN"失望地看看你，慢慢地轉過頭去，跟其他人說話去了。\n"NOR,
	CYN"嚷道：真是個飯桶！\n"NOR,
});

int quest();
int difficult();
protected string get_quest_fail_msg();
void create()
{
	set_name(WHT "阿卡拉" NOR, ({ "a kala" }) );

	set("gender", "男性");
	set("reward_npc", 1);
	set("difficulty", 80); 
	set("age", 26);
	set("attitude", "peaceful");
	set("skill_public",1);
	set("str", 26);
	set("con", 30);
	set("int", 24);
	set("dex", 30);
	set("per", 50);
	set("vendor_goods", ([
	]) );
	set("combat_exp", 2000000);
	set("score", 0);
	set_skill("literate",200);
	set_skill("dodge",200);
	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("parry", 100);
	set_skill("dagger",200);

	set_temp("apply/attack",300);
	set_temp("apply/damage",30000);

	set("title", HIY "暗黑使者" NOR);
	set("can_vision",240);
	set("zone","roger");
	setup();
	set_coor();
	set("inquiry", ([
	        "help":(: do_task :),
		"job":(: do_task :),
		"cancel":(: do_cancel :),
		"difficult" :(:difficult:),
	]) );
}

void init()
{       
	object ob; 
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
	add_action("do_buy", "buy");
	add_action("do_choose","choose");
	add_action("get_forge","agree");
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "阿卡拉說道：這位" + RANK_D->query_respect(ob) + "可以用ask a kala about help來領任務，choose 1-5選擇難度\n");
		break;
		case 1:
                   say( "阿卡拉說道：這位" + RANK_D->query_respect(ob) + "現在可以接暗黑破壞神任務了！\n");
		break;
	}
}

int do_choose(string arg)
{
	int diff;
	if( !arg || !sscanf(arg, "%d", diff) ) 
		return notify_fail(WHT"你只能選擇難度1-5之間的數字。\n"NOR);
	if( (diff>5)||(diff<1) )
		return notify_fail(WHT"你只能選擇難度1-5之間的數字。\n"NOR);
        set("diablo/level",diff,this_player());
	tell_object(this_player(),WHT"你選擇了難度"+arg+"\n"NOR);
	return 1;
}

int difficult()
{
	tell_object(this_player(),"請choose 1-5選擇難度。\n");
	return 1;
}

int do_task()
{
	object *list, *ob, ob1;
	object me = this_player();
	object npcs,obj,room,*team,member;
	
	int level,i,t,lv,just;
	string  *ks;
	string kind,where,msg;
	mapping trans;

	trans=query("trans_act1",me);
        if(mapp(trans)) ks=keys(trans);
        if(!ks) ks=({"blood"});

	if(query("combat_exp",me)  < 1000000 )
	{
	        tell_object(me,CYN"阿卡拉嘆了口氣說：你雖有心，但經驗不夠，不要白白送命。\n"NOR);
		return 1;
	}
	
	//if( !(query("quest/quest",me)== "探訪暗黑城" )&& !(query("quest/quest",me)=="協助阿卡拉" ) )
	//	tell_object(me,"你沒從天機老人接到關於探訪暗黑城的任務，不過可以直接做暗黑城任務，但不能獲得經驗，只能獲得潛能。\n");
		
	if( query("diablo/get",me) )
	{	
		if( !query("diablo/npcs",me) ) {
			message_vision(CYN"阿卡拉說道：你的目標消失。\n"NOR,me);
			return do_cancel();
		} else
		{
		        if( query("diablo/kind",me)=="狙殺") message_vision(CYN"阿卡拉說道：我已經讓你去殺"+query("diablo/npcs",me)->name()+"了嗎，還不快快起程。\n"NOR,me);
			if( query("diablo/kind",me)=="清剿") message_vision(CYN"阿卡拉說道：我已經讓你去清剿"+query("diablo/npcs",me)->name()+"了嗎，還不快快起程。\n"NOR,me);
	        }
                return 1;
	}
	
	t= (int) query("diablo/start_time",me);  
	if( query("diablo/fail",me))
	{ 
		if( objectp(obj = query("diablo/npcs",me))) destruct(obj);
		if( t<=time() && time()<t+3 ) {
			message_vision(CYN"$N沉思片刻說:"+"：這位"+RANK_D->query_respect(me)+"這點小事都幹不了，還不去反省反省。\n"NOR,
			this_object(), me);
			return 1;
		}
	        delete("diablo/fail",me);
	}
	if( !(level=query("diablo/level",me))) level=1;   
 
	i = random(2);
	if (i==0) kind="狙殺";
	if (i==1) kind="清剿";
	if (i==2) kind="切磋";
	if (i==3) kind="逐個擊破";
	if (i==4) kind="勸服";
	if (i>=5) kind="幫助";

        set("diablo/get",time(),me);
        set("diablo/kind",kind,me);


	room=environment(this_object());
	switch (kind) {
		case "狙殺":
			npcs = new("/d/war/npc/questkiller");
		        set("difficulty_level",level,npcs);
				
			npcs->auto_npc_setup(me,"killer",0,0,1,"/clone/weapon/","random","random",level);
		
		        set("chat_chance_combat",level*3,npcs);
		        set("no_death_penalty",1,npcs);
		        set("zone",ks[random(sizeof(ks))],npcs);	
			npcs->move(room);
			npcs->set_coor();
		        set("diablo/npcs",npcs,me);
			tell_object(me,CYN"\n阿卡拉說道：帶現有一暗黑怪物，冒名玩家"+npcs->query_idname()+
				"，此人目前在"+environment()->query_zone(npcs)["name"]+"，你這就去把他狙殺，為民除害。\n"NOR);
	  	break;
	  	case "清剿":
	  		
	  	npcs=new("/d/war/obj/cave");
	        set("owner_id",me,npcs);
	        set("zone",ks[random(sizeof(ks))],npcs);	
	  	npcs->set_door();
	        set("level",to_int(pow(query("combat_exp",me)*8,0.3)),npcs);
	  	npcs->move(room);
	        set("diablo/npcs",npcs,me);
	        set("diablo/zone",replace_string(sprintf("%O.c", npcs), "\"", ""),me);
	  	
	        tell_object(me,CYN"\n阿卡拉說道：帶現有一廢棄的洞穴，目前在"+environment()->query_zone(npcs)["name"]+"，你需要清剿裡面所有的怪物。\n"NOR);
	  	 
	  	break;
	  	
	}
	

        set("diablo/start_time",time(),me);
        set("diablo/level",level,me);
	//if (query("quest/quest",me)=="探訪暗黑城"||query("quest/quest",me)=="協助阿卡拉" ) 	
	{      
	        set("quest/quest_type","special",me);
	        set("quest_time",time(),me);
	        set("quest/cancel",50,me);
	        set("quest/difficulty",380,me);
	        set("quest/quest","協助阿卡拉",me);
	        set("quest/long","協助阿卡拉",me);
	        set("quest/short","協助阿卡拉",me);
	        set("quest/duration",3600,me);
		tell_team(me,HIY+me->name()+HIY"的任務改變了！\n"NOR);
	}
        //else set("tj_akala",1,me);
	msg = me->name()+"接到一個難度"+chinese_number(query("diablo/level",me))+"的任務。";
	message_vision(CYN"\n"+msg+"\n"NOR,me);
	return 1;
}	

int do_cancel()
{
	object me = this_player();
	object obj;

	if( !query("diablo/get",me) ) return notify_fail("你沒有任務在身。\n");
	me->command("say 這個任務在下恐怕無能為力。");
	tell_object(me,query("name")+get_quest_fail_msg());
        set("diablo/fail",1,me);
        delete("diablo/get",me);
        delete("diablo/zone",me);
        delete("diablo/kind",me);

	if( objectp(obj = query("diablo/npcs",me)) ) destruct(obj);
	return 1;
}

string get_quest_fail_msg()
{
        return quest_fail_msg[ random( sizeof( quest_fail_msg ) ) ];
}


