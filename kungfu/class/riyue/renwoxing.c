// renwoxing.c

#include <ansi.h>
#include "riyue.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_COAGENT;

int ask_bijian();
string ask_jing();
mixed no_learn();
mixed ask_pfm();

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_skill4();
mixed ask_skill5();
mixed try_to_learn_xixingdafa();

void create()
{
        set_name("任我行", ({ "ren woxing", "ren","woxing" }));
        set("title", GRN "日月神教教主" NOR );
        set("long", "只見他一張長長的臉孔，臉色雪白，更無半分血色，眉目清秀，
身材甚高，一頭黑髮，穿的是一襲青衫。\n");
        set("gender", "男性");
        set("class", "scholar");
        set("age", 55);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("per", 27);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("yijinjing_count", 1);

        set("max_qi", 7000);
        set("max_qi", 700000);
        set("max_jing", 50000);
        set("neili", 90000);
        set("max_neili", 90000);
        set("jiali", 400);
        set("combat_exp", 40000000);
        set("score", 50000);

        set_skill("force", 700);
        set_skill("riyue-xinfa", 700);
        set_skill("xixing-dafa", 700);
        set_skill("tianhuan-shenjue", 900);
        set_skill("yijinjing", 600);
        set_skill("tianmo-jian", 700);
        set_skill("riyue-jian", 700);
        set_skill("strike", 900);
        set_skill("guzhuo-zhang", 900);
        set_skill("qingmang-zhang", 900);
        set_skill("cuff", 700);
        set_skill("zhenyu-quan", 900);
        set_skill("xuwu-piaomiao", 700);
        set_skill("hand", 700);
        set_skill("lansha-shou", 900);
        set_skill("huanmo-longtianwu", 700);
        set_skill("claw", 900);
        set_skill("poyue-zhao", 900);
        set_skill("literate", 700);
        set_skill("dodge", 700);
        set_skill("unarmed", 700);
        set_skill("piaomiao-shenfa", 700);
        set_skill("parry", 700);
        set_skill("sword", 700);
        set_skill("yuanshi-jian", 900);
        set_skill("damo-jian", 600);
        set_skill("taiji-jian", 600);
        set_skill("huifeng-jian", 600);
        set_skill("taishan-sword", 600);
        set_skill("hengshan-jian", 600);
        set_skill("hengshan-sword", 600);
        set_skill("huashan-sword", 600);
        set_skill("songshan-sword", 600);
        set_skill("blade", 900);
        set_skill("danding-dao", 900);
        set_skill("throwing", 900);
        set_skill("heixue-shenzhen", 900);
        set_skill("literate", 320);
        set_skill("martial-cognize", 900);
        set_skill("richu-dongfang", 600);        

        map_skill("dodge", "piaomiao-shenfa");
        map_skill("force", "xixing-dafa");
        map_skill("strike", "guzhuo-zhang");
        map_skill("sword", "yuanshi-jian");
        map_skill("parry", "guzhuo-zhang");
        map_skill("hand", "lansha-shou");
        map_skill("cuff", "zhenyu-quan");
        map_skill("claw", "poyue-zhao");
        map_skill("blade", "danding-dao");
        map_skill("throwing", "heixue-shenzhen");

        prepare_skill("strike", "guzhuo-zhang");

        set("no_teach", ([
                "xixing-dafa"    : (: try_to_learn_xixingdafa :),
                "yijinjing"      : "易筋經神功乃少林絕技，我雖習得，卻也未得要領。",
                "damo-jian"      : (: no_learn :),
                "taiji-jian"     : (: no_learn :),
                "huifeng-jian"   : (: no_learn :),
                "taishan-sword"  : (: no_learn :),
                "hengshan-jian"  : (: no_learn :),
                "hengshan-sword" : (: no_learn :),
                "huashan-sword"  : (: no_learn :),
                "songshan-sword" : (: no_learn :),
        ]));

        create_family("日月神教", 1, "教主");
        
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        set("inquiry", ([
                "吸星大法" : "我寫的拓本還遺留在梅莊未曾取回，你去找找吧。\n",
                "比劍"     : (: ask_bijian :),
                "劍法"     : (: ask_bijian :),
                "易筋經"   : (: ask_jing :),
                "黑木令"   : "要拿黑木令？老夫想先看看你的劍法！\n",
                "絕招"     : (: ask_pfm :),
                "一劍穿心" : (: ask_pfm :),
                "天地歸元" : (: ask_skill1 :),
                "天旋地轉" : (: ask_skill2 :),
                "大巧若拙" : (: ask_skill3 :),
                "大智若愚" : (: ask_skill4 :),
                "反璞歸真" : (: ask_skill5 :),
        ]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.gui" :),
		(: perform_action, "sword.xuan" :),
                (: perform_action, "strike.zhuo" :),
                (: perform_action, "strike.yu" :),
                (: perform_action, "strike.zhen" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: exert_function, "suck" :),
	}) );

        set("master_ob", 5);
        setup();
        carry_object("/d/wudang/obj/bluecloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if(! permit_recruit(ob))  return;

        if( query("shen", ob)>-80000 )
        {
                command("sneer");
                command("say 老夫平生最痛恨的就是你這樣的假仁假義之徒。");
                return;
        }

        if( query("combat_exp", ob)<500000 )
        {
                command("say 你現在江湖經驗太淺，還是先跟隨幾位長老學習吧。");
                return;
        }

	if (ob->query_int() < 34)
	{
		command("hmm");
		command("say 你悟性那麼差，怎麼領會我的武功？");
		return;
	}

        if (ob->query_skill("tianhuan-shenjue", 1) < 150
           && ob->query_skill("riyue-xinfa", 1) < 150)
        {
                command("hmm");
                command("say 你連本門最基本的內功都沒修好，怎麼學習上乘武學。");
                return;
        }

        command("nod2");
        command("say 念在你如此有心，對本教又忠心耿耿，今日我便收你為徒。");
        command("say 我日月神教一統江湖的千秋大業，就全靠你們了。");
        command("recruit "+query("id", ob));
        set("title", HIR"日月神教大護法"NOR, ob);
        return;
}

mixed try_to_learn_xixingdafa()
{
        object ob = this_player();

        if (query("can_learn/xixing-dafa/ren", ob))
                return 0;

        if (ob->query_skill("force", 1) > 180)
        {
                command("say 你此時的功力已頗為深厚，今日我就傳你吸星大法。");
	        command("whisper " + query("id", ob) + " 壓抑內力反噬的口訣"
                        "是%X&$&$%$$#$#，可記好了。");
                set("can_learn/xixing-dafa/ren", 1, ob);
                return 0;
        }

        return "你此時功力太淺，強修此功會走火入魔。";
}
int ask_bijian()
{
        object obj, me = this_player(), ob = this_object();
        message_vision("$N躬身說道：“晚輩今日有幸拜見任老前輩，還望多加指教。”\n$n笑道：“不用客氣，你來解我寂寞，可多謝你啦。”\n", me, ob );
        message_vision("$N道：“不敢。”\n$n點了點頭，說道：“我只想瞧瞧你的劍法，並非真的過招，再說，我也未必能勝得了你。”\n\n", me, ob);
        command("enable sword damo-jian");
        say(HIR"任我行大喝一聲：“少林劍法！”"NOR);
        COMBAT_D->do_attack(ob, me, query_temp("weapon"));
        if( query("qi", me)<0 || !present(me,environment()) )
        {
                say("任我行嘆了口氣，說道：“才一招。”\n");
                command("enable sword tianmo-jian");
                return 1;
        }
        command("enable sword taiji-jian");
        say(HIR"任我行大喝一聲：“武當劍法！”"NOR);
        COMBAT_D->do_attack(ob, me, query_temp("weapon"));
        if( query("qi", me)<0 || !present(me,environment()) )
        {
                say("任我行嘆了口氣，說道：“才兩招。”\n");
                command("enable sword tianmo-jian");
                return 1;
        }
        command("enable sword huifeng-jian");
        say(HIR"任我行大喝一聲：“峨嵋劍法！”"NOR);
        COMBAT_D->do_attack(ob, me, query_temp("weapon"));
        if( query("qi", me)<0 || !present(me,environment()) )
        {
                say("任我行嘆了口氣，說道：“才三招。”\n");
                command("enable sword tianmo-jian");
                return 1;
        }
        command("enable sword songshan-sword");
        say(HIR"任我行大喝一聲：“嵩山劍法！”"NOR);
        COMBAT_D->do_attack(ob, me, query_temp("weapon"));
        if( query("qi", me)<0 || !present(me,environment()) )
        {
                say("任我行嘆了口氣，說道：“才四招。”\n");
                command("enable sword tianmo-jian");
                return 1;
        }

        command("enable sword taishan-sword");
        say(HIR"任我行大喝一聲：“泰山劍法！”"NOR);
        COMBAT_D->do_attack(ob, me, query_temp("weapon"));
        if( query("qi", me)<0 || !present(me,environment()) )
        {
                say("任我行嘆了口氣，說道：“才五招。”\n");
                command("enable sword tianmo-jian");
                return 1;
        }
        command("enable sword huashan-sword");
        say(HIR"任我行大喝一聲：“華山劍法！”"NOR);
        COMBAT_D->do_attack(ob, me, query_temp("weapon"));
        if( query("qi", me)<0 || !present(me,environment()) )
        {
                say("任我行嘆了口氣，說道：“才六招。”\n");
                command("enable sword tianmo-jian");
                return 1;
        }
        command("enable sword hengshan-sword");
        say(HIR"任我行大喝一聲：“衡山劍法！”"NOR);
        COMBAT_D->do_attack(ob, me, query_temp("weapon"));
        if( query("qi", me)<0 || !present(me,environment()) )
        {
                say("任我行嘆了口氣，說道：“才七招。”\n");
                command("enable sword tianmo-jian");
                return 1;
        }
        command("enable sword hengshan-jian");
        say(HIR"任我行大喝一聲：“恆山劍法！”"NOR);
        COMBAT_D->do_attack(ob, me, query_temp("weapon"));
        if( query("qi", me)<0 || !present(me,environment()) )
        {
                say("任我行嘆了口氣，說道：“還是沒過八招。”\n");
                command("enable sword tianmo-jian");
                return 1;
        }
        if( query_temp("heimuling", me) )
                say("任我行說道：“哈哈，這位" + RANK_D->query_respect(me) +"武功不錯，快去幫我殺了東方不敗那個閹賊！”\n");
        else
        {
                say("任我行說道：“這位" + RANK_D->query_respect(me) +"不錯，我就送你一塊黑木令吧。”\n");
                set_temp("heimuling", 1, me);
        }
        obj = new("/d/heimuya/obj/heimu-ling");
        obj -> move(me);
        command("enable sword tianmo-jian");
        return 1;
}

mixed no_learn()
{
        command("shake");
        command("say 這功夫是我閒時練來玩的，也不知練得對不對，你就不要學了。");
        return -1;
}

mixed ask_pfm()
{
        object me = this_player();

        if( query("can_perform/tianmo-jian/chuanxin", me) )
                return RANK_D->query_respect(me) + "是想和老夫切磋一下武藝？";

        if( query("family/family_name", me) != query("family/family_name") )
                return "本教武功獨步武林，這位" + RANK_D->query_respect(me) +
                       "既然想學，不如入我日月神教如何？";

        if (me->query_skill("tianmo-jian", 1) < 250)
                return "你的天魔劍法尚欠火候，還領悟不了這招，再多練練去吧！";

        message_vision(HIY "$n" HIY "對$N" HIY "點了點頭：這招講究以意馭劍，瞧仔細了。\n" HIW
                       "只見$n" HIW "雙足一點，騰空而起，手中長劍前探，緊跟著身子連轉" HIW
                       "數圈，一道白影筆直向$N" HIW "射來。\n" NOR,
                       me, this_object());
        
        say(HIC"任我行飄然而落，還劍入鞘，微笑道：“看懂了沒有？”\n"NOR);
        tell_object(me, HIY "你學會了「一劍穿心」這一招。\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 160000);
        set("can_perform/tianmo-jian/chuanxin", 1, me);
        return 1;
}

string ask_jing()
{
        object me, ob;
        string msg;

        me = this_player();
        if( query("family/family_name", me) != query("family/family_name") )
                return "少林易筋經神功名滿江湖，若有幸習得，終生受用不盡。";

        if( query("family/master_id", me) != query("id") )
                return "據說曾有少林高僧將經文記錄下來，不知是真是假。";


        if (objectp(present("yijinjing", me)))
                return "你不是已有經書了，還問我做什麼。";

        if( query_temp("ask_jing", me) && time()-query_temp("ask_jing", me)<120 )
                return "跟你說了經書不在老夫身上，你不相信麼？";

        if (random(3) != 0 || query("yijinjing_count") < 1)
        {
                if( query_temp("ask_jing", me) )
                        msg = "老夫還未曾將經書找回，你再等等吧。";
                else
                        msg = "經書此時並不在老夫身上。";
                set_temp("ask_jing", time(), me);
                return msg;
        }

        addn("yijinjing_count", -1);
        ob = new("/clone/book/yijinjing");
        ob->move(me);
        return "這卷經文你可要小心收好，千萬勿示於他人。";
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if( query("can_perform/yuanshi-jian/gui", me) )
                return "這一招我不是已經教過你了嗎？";

        if( query("family/family_name", me) != query("family/family_name") )
                return "你又不是我日月神教的，跑來搗什麼亂？";

        if (me->query_skill("yuanshi-jian", 1) < 1)
                return "你連原始劍法都沒學，還談什麼絕招可言？";

        if( query("family/gongji", me)<500 )
                return "你在教內甚無作為，這招我暫時還不能傳你。";

        if( query("shen", me)>-120000 )
                return "你這樣心慈手軟，就算學會這招又有什麼用？";

        if (me->query_skill("force") < 200)
                return "你的內功火候尚需提高，練好了再來找我吧。";

        if (me->query_skill("yuanshi-jian", 1) < 140)
                return "你的原始劍法還練得不到家，自己下去練練再來吧！";

        message_sort(HIY "\n$n" HIY "點了點頭，隨即便將$N" HIY "招至身邊"
                     "，在耳旁低聲細說良久，$N" HIY "聽後會心的一笑，看來"
                     "大有所悟。\n\n" NOR, me, this_object()); 

        command("nod2");
        command("say 剛才我說的全是此招的精要，可要記牢了。");
        tell_object(me, HIC "你學會了「天地歸元」。\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("yuanshi-jian"))
                me->improve_skill("yuanshi-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        set("can_perform/yuanshi-jian/gui", 1, me);
        addn("family/gongji", -500, me);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if( query("can_perform/yuanshi-jian/xuan", me) )
                return "這一招我不是已經教過你了嗎？";

        if( query("family/family_name", me) != query("family/family_name") )
                return "你又不是我日月神教的，跑來搗什麼亂？";

        if (me->query_skill("yuanshi-jian", 1) < 1)
                return "你連原始劍法都沒學，還談什麼絕招可言？";

        if( query("family/gongji", me)<1400 )
                return "你在教內甚無作為，這招我暫時還不能傳你。";

        if( query("shen", me)>-130000 )
                return "你這樣心慈手軟，就算學會這招又有什麼用？";

        if (me->query_skill("force") < 260)
                return "你的內功火候尚需提高，練好了再來找我吧。";

        if (me->query_skill("yuanshi-jian", 1) < 180)
                return "你的原始劍法還練得不到家，自己下去練練再來吧！";

        message_sort(HIY "\n$n" HIY "微微一笑，從懷中輕輕取出了一本劍譜"
                     "，指著其中一段對$N" HIY "細說良久，$N" HIY "一邊聽"
                     "一邊不住地點頭。\n\n" NOR, me, this_object());

        command("nod");
        command("say 你只需記住‘以快打慢、制人機先’這八個字便成。");
        tell_object(me, HIC "你學會了「天旋地轉」。\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("yuanshi-jian"))
                me->improve_skill("yuanshi-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        set("can_perform/yuanshi-jian/xuan", 1, me);
        addn("family/gongji", -1400, me);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if( query("can_perform/guzhuo-zhang/zhuo", me) )
                return "這一招我不是已經教過你了嗎？";

        if( query("family/family_name", me) != query("family/family_name") )
                return "你又不是我日月神教的，跑來搗什麼亂？";

        if (me->query_skill("guzhuo-zhang", 1) < 1)
                return "你連古拙掌法都沒學，還談什麼絕招可言？";

        if( query("family/gongji", me)<600 )
                return "你在教內甚無作為，這招我暫時還不能傳你。";

        if( query("shen", me)>-120000 )
                return "你這樣心慈手軟，就算學會這招又有什麼用？";

        if( query("max_neili", me)<1800 )
                return "你的內力太差，怎麼修煉上乘武功？";

        if (me->query_skill("force") < 220)
                return "你的內功火候尚需提高，練好了再來找我吧。";

        if (me->query_skill("guzhuo-zhang", 1) < 150)
                return "你的古拙掌法還練得不到家，自己下去練練再來吧！";

        message_sort(HIY "\n$n" HIY "冷笑一聲，更不答話，只是隨手揮出一掌"
                     "，毫無半點招式可言。可哪知這看似不經意的一掌，竟激得"
                     "周圍塵沙四起，掌風呼嘯而至，直颳得$N" HIY "面龐隱隱"
                     "生疼。招式之巧，實乃$N" HIY "前所未聞。\n\n" NOR, me,
                     this_object());

        command("nod");
        command("say 明白了嗎？");
        tell_object(me, HIC "你學會了「大巧若拙」。\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("guzhuo-zhang"))
                me->improve_skill("guzhuo-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        set("can_perform/guzhuo-zhang/zhuo", 1, me);
        addn("family/gongji", -600, me);

        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();

        if( query("can_perform/guzhuo-zhang/yu", me) )
                return "這一招我不是已經教過你了嗎？";

        if( query("family/family_name", me) != query("family/family_name") )
                return "你又不是我日月神教的，跑來搗什麼亂？";

        if (me->query_skill("guzhuo-zhang", 1) < 1)
                return "你連古拙掌法都沒學，還談什麼絕招可言？";

        if( query("family/gongji", me)<1200 )
                return "你在教內甚無作為，這招我暫時還不能傳你。";

        if( query("shen", me)>-150000 )
                return "你這樣心慈手軟，就算學會這招又有什麼用？";

        if( query("max_neili", me)<2800 )
                return "你的內力太差，怎麼修煉上乘武功？";

        if (me->query_skill("force") < 260)
                return "你的內功火候尚需提高，練好了再來找我吧。";

        if (me->query_skill("guzhuo-zhang", 1) < 180)
                return "你的古拙掌法還練得不到家，自己下去練練再來吧！";

        message_sort(HIY "\n$n" HIY "大笑數聲，對$N" HIY "讚道：“想不到你"
                     "的掌法居然已達如此造詣，今日老夫傳你這招又有何妨？”"
                     "$n" HIY "隨即擺開架勢，慢慢的演示招數。\n\n" NOR, me,
                     this_object());

        command("haha");
        command("say 只需明白了這個道理，這招大愚掌便已練成了。");
        tell_object(me, HIC "你學會了「大智若愚」。\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("guzhuo-zhang"))
                me->improve_skill("guzhuo-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        set("can_perform/guzhuo-zhang/yu", 1, me);
        addn("family/gongji", -1200, me);

        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();

        if( query("can_perform/guzhuo-zhang/zhen", me) )
                return "這一招我不是已經教過你了嗎？";

        if( query("family/family_name", me) != query("family/family_name") )
                return "你又不是我日月神教的，跑來搗什麼亂？";

        if (me->query_skill("guzhuo-zhang", 1) < 1)
                return "你連古拙掌法都沒學，還談什麼絕招可言？";

        if( query("family/gongji", me)<2200 )
                return "你在教內甚無作為，這招我暫時還不能傳你。";

        if( query("shen", me)>-200000 )
                return "你這樣心慈手軟，就算學會這招又有什麼用？";

        if( !query("can_perform/guzhuo-zhang/zhuo", me )
            || !query("can_perform/guzhuo-zhang/yu", me) )
                return "你連前兩招都未練成，怎麼學這最後一招？";

        if( query("max_neili", me)<3600 )
                return "你的內力太差，怎麼修煉上乘武功？";

        if (me->query_skill("force") < 300)
                return "你的內功火候尚需提高，練好了再來找我吧。";

        if (me->query_skill("guzhuo-zhang", 1) < 220)
                return "你的古拙掌法還練得不到家，自己下去練練再來吧！";

        message_sort(HIY "\n$n" HIY "對$N" HIY "微微點了點頭，沉聲說道："
                     "“看來你這套古拙掌法已經練得相當純熟了，今日老夫就"
                     "傳你這招。”說完便將$N" HIY "招至跟前細說良久，陡然"
                     "間只見$n" HIY "忽然探出右手，平推而出，$N" HIY "只"
                     "覺掌風澎湃，凌厲之極，頓時胸口一陣鬱悶，難受得說不"
                     "出話來。\n\n" NOR, me, this_object());

        command("haha");
        command("say 兩招合一便是新招，你明白了嗎？");
        tell_object(me, HIC "你學會了「反璞歸真」。\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("guzhuo-zhang"))
                me->improve_skill("guzhuo-zhang", 1500000);
        if (me->can_improve_skill("guzhuo-zhang"))
                me->improve_skill("guzhuo-zhang", 1500000);
        if (me->can_improve_skill("guzhuo-zhang"))
                me->improve_skill("guzhuo-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        set("can_perform/guzhuo-zhang/zhen", 1, me);
        addn("family/gongji", -2200, me);

        return 1;
}
void reset()
{
     set("yijinjing_count", 1);
}
