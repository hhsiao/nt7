// jiaoshi.c 教士

#include <ansi.h>

#define MARRY_RING      "/clone/misc/wedding-ring.c"
#define RING_DIR        "/data/item/ring/"

inherit NPC;

void create()
{
	set_name("西洋傳教士", ({ "jiao shi", "jiaoshi", "marriage witness" }));
	set("long", 
		"他穿著一身的黑色服飾，神色肅穆。\n");
	set("gender", "男性");
	set("age", 35);
	set("combat_exp", 1000);

        set("inquiry", ([
                "結婚": "要結婚是嗎？大家都是上帝的子女，我可以為你們證婚。",
                "離婚": "雖然離婚讓人感到痛苦，但是也許湊在一起更讓人痛苦！",
        ]));

	setup();
        seteuid(getuid());
}

int do_witness(object me, object ob)
{
        message_vision("$N含情脈脈的望著$n，真是柔情似水，過了良久才對" +
                       name() + "道：這位先生做我們的證婚人吧！\n\n",
                       me, ob);

        if (! living(ob))
        {
                message_vision(name() + "目瞪口呆了半點才對$N道：我"
                               "看你還是先把這位弄醒再說吧。\n", me);
                return 1;
        }

        if (! userp(ob))
        {
                message_vision(name() + "滿臉都是苦笑，笑啥"
                               "呢？你也呵呵的跟著傻笑。\n", me);
                return 1;
        }

        message_vision(name() + "點點頭道：“很好，很好！大家都是"
                       "上帝的子女，這個沒有問題。問題是你們都是兩相情願嗎？”\n"
                       "說罷轉過頭來，對$n問道：“你願意和" +
                       (query("gender", me) == "女性"?"她":"他")+
                       "結為夫妻嗎(right/refuse)？”\n", me, ob);

        set_temp("pending/answer/"+query("id", me)+"/right",
                     bind((: call_other, __FILE__, "do_right", ob, me :), ob), ob);
        set_temp("pending/answer/"+query("id", me)+"/refuse",
                     bind((: call_other, __FILE__, "do_refuse", ob, me :), ob), ob);
set_temp("pending/engage", ob, 	me);
        return 1;
}

int do_right(object me, object ob)
{
        string fn;
        string fc;
        object ring;

        message_vision("$N看了看$n，點頭道：“我願意！”\n", me, ob);
        command("chat 很好，我現在宣佈：" + me->name(1) + "和" + ob->name(1) +
                "已經成為合法的夫妻了！");
        message("visoin", name() + "笑著對二人說：“這對結婚"
                "戒指送給你們，就算是我的禮物吧！”\n\n", environment(me));

        fc = read_file(MARRY_RING);
        fc = replace_string(fc, "LONG_DESCRIPTION",
                            "這是" + me->name(1) + "和" +
                            ob->name(1) + "的結婚戒指，是兩人的定情之物。\n");

        // give ring to me
        fn=RING_DIR+query("id", me);
        if (file_size(fn + ".c") > 0)
        {
                if (ring = find_object(fn)) destruct(ring);
                rm(fn + ".c");
        }
        assure_file(fn);
        write_file(fn + ".c", fc);
        VERSION_D->append_sn(fn + ".c");
        ring = load_object(fn);
        ring->move(me, 1);
        tell_object(me, HIY "你獲得了一個結婚戒指。\n" NOR);
        set("can_summon/"+"weddingring", fn, me);

        // give ring to ob
        fn=RING_DIR+query("id", ob);
        if (file_size(fn + ".c") > 0)
        {
                if (ring = find_object(fn)) destruct(ring);
                rm(fn + ".c");
        }
        assure_file(fn);
        write_file(fn + ".c", fc);
        VERSION_D->append_sn(fn + ".c");
        ring = load_object(fn);
        ring->move(ob, 1);
        tell_object(ob, HIY "你獲得了一個結婚戒指。\n" NOR);
        set("can_summon/"+"weddingring", fn, ob);
        
        // record
set("couple/id",query("id",  ob), 	me);
set("couple/name", ob->name(1), 	me);
        set("couple/witness", name(), me);
	me->save();
set("couple/id",query("id",  me), 	ob);
set("couple/name", me->name(1), 	ob);
        set("couple/witness", name(), ob);
	ob->save();
        return 1;
}

int do_refuse(object me, object ob)
{
        message_vision("$N瞥了$n一眼，轉過頭去不再看，連吐了"
                       "幾口，“呸、呸、我呸呸呸！”\n" +
                       name() + "無奈的對$n道：“一廂情願是不行的，"
                       "那是犯罪...你還是算了吧。”\n", me, ob);
        return 1;
}

int do_divorce(object me)
{
        object ob;

        if( query("couple/witness", me) != name() )
        {
                message_vision(name() + "搖搖頭，對$N道：“我"
                               "不是你們的證婚人，你們離婚不要找我！”\n", me);
                return 1;
        }

        ob=find_player(query("couple/id", me));
        if (! ob || environment(ob) != environment(me))
        {
                message_vision(name() + "吃驚的看著$N道：“怎麼，要離婚？"
                               "不過要離你怎麼也得把人家找來啊！”\n", me);
                return 1;
        }

        if (! living(ob))
        {
                message_vision(name() + "搖搖頭，對$N道：“我說這位" +
                               RANK_D->query_respect(me) +
                               "，怎麼也得等人家醒過來再說吧！”\n", me);
                return 1;
        }

        if( query_temp("pending/submit_divorce", me) )
        {
                message_vision(name() + "搖搖頭，對$N道：“你著"
                               "什麼急，也不看看人家的意思？”\n",
                               me);
                return 1;
        }

        if( !query_temp("pending/submit_divorce", ob) )
        {
                message_vision(name() + "嘆了口氣，回頭看了看$n，問道：“你"
                               "決定要和" + ob->name() + "離婚嗎？”\n\n", me, ob);
                tell_object(ob, YEL + name() + "悄悄的告訴你：要是那樣，你就輸入("
                                "divorce"+query("id", me)+")表示決心已定。\n");
                set_temp("pending/submit_divorce", 1, me);
                return 1;
        }

        message_vision(name() + "慢慢的對$N和$n道：“既然你們雙方"
                       "已經不願意在一起了，那就分開吧！”\n\n", me, ob);
        command("chat 從今天起" + me->name(1) + "和" + ob->name(1) +
                "不再是夫妻了，他們以後沒有什麼關係了！");
        UPDATE_D->clear_user_data(query("id", me),"couple");
        return 1;
}

int accept_fight()
{
        command("shake");
        command("say 我來中國不是打架來的，如果你有興趣可以找我們的大力士。");
        return notify_fail("你還是算了吧！\n");
}

int accept_hit()
{
        command("fear");
        command("say 你怎麼能隨便打人？");
        return notify_fail("你還是算了吧！\n");
}

int accept_kill()
{
        command("say 中國人好野蠻啊！你怎麼能這樣？");
        return 1;
}

void unconcious()
{
        die();
}

void die()
{
        command("chat 中國人真野蠻！走了走了。");
        message_vision("$N急忙溜走了。\n", this_object());
        destruct(this_object());
}
