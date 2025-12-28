/*
void init()
{
	::init();
	add_action("do_kill", "kill");
        add_action("do_kill", "tk");
        add_action("do_kill", "teamkill");
        add_action("do_kill", "hit");
}

int do_kill(string arg)
{
        object me, ob,ob2;
        me = this_player();
        ob2 = this_object();

        if (!arg) return 0;
        ob = present(arg, environment(me));
        if (ob == this_object() || ob == me) return 0;
        if (!ob || !ob->is_character()) return 0;

	if (ob->query("family/family_name") == "天龍寺") {
                if (me->query("family/family_name") == "天龍寺") {
                        message_vision(ob2->name()+"向$N沉聲喝道：出家人戒殺生，怎麼連自己的同門都殺？！\n", me);
                }
                else {
                        message_vision(ob2->name()+"向$N沉聲喝道：大膽狂徒，居然來天龍寺行兇！\n", me);
                        kill_ob(me);
                }
                me->set("vendetta/天龍寺", 1);
                return 1;
        }
        return 0;
}
*/

void attempt_apprentice(object ob)
{
       object me  = this_object();
       mapping ob_fam = ob->query("family");
       mapping my_fam = me->query("family");
       string name, new_name;

	if (!ob_fam || ob_fam["family_name"] != "天龍寺"){
		command("say "+RANK_D->query_respect(ob)+"與本寺素無來往，不知此話從何談起？");
		return;
	}
	if (!ob->query("tls")){
		command("say "+RANK_D->query_respect(ob)+"不是本寺出家弟子，我不能收你! ");
		return;
	}
	if (ob_fam["generation"] <= my_fam["generation"] ){
		command("say "+RANK_D->query_respect(ob)+"，貧僧哪裡敢當！");
		return;
	}
	if (ob_fam["generation"] == (my_fam["generation"] + 1)){
		command("say "+ob_fam["master_name"]+"最近禪功繁忙，你就過來跟著我學習吧。");
		command("recruit " + ob->query("id"));
		return;
	}
	if((int)ob->query_skill("buddhism",1)<100){
		command("say 學武只是為了強身健體，而佛學才是我天龍的主要修行功課。");
		command("say 依我看"+RANK_D->query_respect(ob)+"禪宗方面的修為似乎還不夠吧？");
		return;
	}
	if((int)ob->query_skill("qiantian-yiyang",1)<100){
		command("say 我天龍武學講究內外兼修，依我看"+RANK_D->query_respect(ob)+"似乎還應在內功方面多下點功夫。");
		return;
	}
	if((int)ob->query("shen") > 100 || (int)ob->query("shen")+100 <0 ){
		command("say 我天龍寺乃清修之地，依我看"+RANK_D->query_respect(ob)+"似乎紅塵未了,不宜繼續修行。");
		return;
	}
	if(ob->query("tls")&&(string)ob->query("class") == "bonze" ){
		command("nod");
		command("say 阿彌陀佛，善哉！善哉！");
		message_vision("$N雙手合十，恭恭敬敬地跪了下來。\n",ob);
		name = ob->query("name");
		new_name = "了" + name[1..1];
		command("say 你這麼刻苦用功，貧僧就收下你吧。從今以後你的法名叫做"+new_name+"。");
		ob->set("name", new_name);
		ob->set("shen", 0);
		command("recruit " + ob->query("id"));
	}
}
