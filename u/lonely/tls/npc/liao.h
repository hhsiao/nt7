string ask_for_join()
{
	object me = this_player();

	if( me->query_temp("tls_chujia"))
		return "阿彌陀佛！施主不是已經問過了嗎？還不拜師（bai)？\n";
	if( (string)me->query("gender") == "女性" )
		return "阿彌陀佛！崇聖寺乃是寺院，女施主若真心皈依我佛，可去峨嵋山受戒。\n";
	if( me->query("tls") && (string)me->query("class")=="bonze" )
		return "阿彌陀佛！大師已是天龍寺內出家之人，何故跟貧僧開這等玩笑？\n";
	if( me->query("marry"))
		return "阿彌陀佛！施主已經結婚，你出家，可讓你家中的妻子可怎麼辦啊？";
	if(me->query_temp("tls_app")) {
		me->delete_temp("tls_app");
		me->set_temp("tls_chujia", 1);
		return "阿彌陀佛！善哉！善哉！施主既是今上所舉，自可入我天龍寺出家，你就拜師(bai)吧。\n";
	}
	return "阿彌陀佛！善哉！善哉！本寺僧侶已滿，施主還是請回吧。\n";
}

void attempt_apprentice(object me)
{
	object ob;
	mapping ob_fam, fam;
	string name, new_name;
	ob = this_object();

	ob_fam = ob->query("family");
	fam = me->query("family");

	if(me->query("gender") != "男性" ){
		command ("say 阿彌陀佛！"+RANK_D->query_respect(me)+"，貧僧可不敢開這等玩笑啊。");
		return;
	}
	if(!fam || fam["family_name"] != "天龍寺"){
		command("say "+RANK_D->query_respect(me)+"與本寺素無來往，不知此話從何談起？");
		return;
	}
	if (me->query("tls") && fam["generation"] <= ob_fam["generation"] ){
		command("say "+RANK_D->query_respect(me)+"，貧僧哪裡敢當！");
		return;
	}
	if (me->query("tls") && fam["generation"] == (ob_fam["generation"] + 1)){
		command("say "+fam["master_name"]+"最近功課繁忙，你就過來跟著我學習吧。");
		command("recruit " + me->query("id"));
		return;
	}
	if(me->query_temp("tls_chujia")){
		command("nod");
		command("say 阿彌陀佛，善哉！善哉！");
		message_vision("$N雙手合十，恭恭敬敬地跪了下來。\n\n"
			"$n伸出手掌，在$N頭頂輕輕地摩挲了幾下，將$N的頭髮盡數剃去。\n\n",me, ob);
		name = me->query("name");
		new_name = "心" + name[<2..<1];

		command("chat " + name + "於今日" + NATURE_D->game_time() + "在天龍寺剃度出家，取法名" + new_name + "！\n");
		command("say 從今以後你的法名叫做" + new_name + "。");
		me->set("name", new_name);
		me->set("class", "bonze");
		me->set("shen", 0);
		me->delete_temp("tls_chujia");
		me->set("tls",1);
		command("recruit " + me->query("id"));
		return;
	}
	else {
		if(!me->query("tls")) {
			command ("say 阿彌陀佛！本寺僧侶已滿，施主還是請回吧。");
			return;
		}
	}
}
