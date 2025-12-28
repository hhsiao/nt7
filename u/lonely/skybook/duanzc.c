#include <ansi.h>
#include "duan.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

// skybook start
#define QUESTDIR  "skybook/天龍八部/"
#define QUESTDIR1 "skybook/天龍八部/凌波微步篇/"
#define QUESTDIR2 "skybook/天龍八部/天龍營救篇/"
#define QUESTDIR3 "skybook/天龍八部/蕭峰身世篇/"
#define QUESTDIR4 "skybook/天龍八部/大遼救援篇/"
#define QUESTDIR5 "skybook/天龍八部/復興天下篇/"
#define QUESTDIR6 "skybook/天龍八部/武功/"

mixed ask_duanyu();
mixed rescue_duanyu();
mixed help_tianlong();
mixed rescue_xiaofeng();
mixed ask_jiumozhi();
// skybook end

mixed ask_wldh();
mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_skill4();
mixed ask_skill5();
mixed ask_skill6();
mixed ask_skill7();

void create()
{
        set_name("段正淳", ({ "duan zhengchun", "duan", "zhengchun" }));
        set("title",  "大理國護國大將軍" );
        set("nickname", HIR "鎮南王" NOR);
        set("long", "他就是大理國的鎮南王，當今皇太弟，是有名的愛情聖手。\n");
        set("gender", "男性");
        set("age", 45);
        set("class", "royal");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 28);
        set("int", 30);
        set("con", 31);
        set("dex", 30);
        set("max_qi", 4500);
        set("max_jing", 3000);
        set("neili", 5800);
        set("max_neili", 5800);
        set("jiali", 200);
        set("combat_exp", 2500000);
        set("score", 50000);

        set_skill("force", 220);
        set_skill("duanshi-xinfa", 220);
        set_skill("dodge", 200);
        set_skill("tiannan-bu", 200);
        set_skill("cuff", 220);
        set_skill("jinyu-quan", 220);
        set_skill("strike", 220);
        set_skill("wuluo-zhang", 220);
        set_skill("sword", 220);
        set_skill("staff", 220);
        set_skill("duanjia-jian", 220);
        set_skill("finger", 200);
        set_skill("qiantian-zhi", 200);
        set_skill("sun-finger", 200);
        set_skill("parry", 220);
        set_skill("jingluo-xue", 180);
        set_skill("literate", 240);
        set_skill("martial-cognize", 200);

        map_skill("force", "duanshi-xinfa");
        map_skill("dodge", "tiannan-bu");
        map_skill("finger", "sun-finger");
        map_skill("cuff", "jinyu-quan");
        map_skill("strike", "wuluo-zhang");
        map_skill("parry", "sun-finger");
        map_skill("sword", "duanjia-jian");
        map_skill("staff", "sun-finger");

        prepare_skill("finger", "sun-finger");

        set("rank_info/respect", "風流王爺");
        create_family("段氏皇族", 15, "傳人");

        set("inquiry", ([
                "乾陽神指" : (: ask_skill1 :),
                "風雲變幻" : (: ask_skill2 :),
                "金玉滿堂" : (: ask_skill3 :),
                "驚天一劍" : (: ask_skill4 :),
                "五絕劍"   : (: ask_skill5 :),
                "哀牢山劍意" : (: ask_skill6 :),
                "一陽劍氣"   : (: ask_skill7 :),
                "武林大會" : (: ask_wldh :),
                "聚賢莊"   : (: ask_wldh :),
// skybook
                "段譽"     : (: ask_duanyu :),
                "鳩摩智"   : (: ask_jiumozhi :),
                "營救段譽" : (: rescue_duanyu :),
                "救援段譽" : (: rescue_duanyu :),
                "解救蕭峰" : (: rescue_xiaofeng :),
                "營救蕭峰" : (: rescue_xiaofeng :),
                "天龍有難" : (: help_tianlong :),       
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "finger.qian" :),
                (: perform_action, "finger.dian" :),
                (: perform_action, "sword.jing" :),
                (: perform_action, "sword.lian" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        set("master_ob", 4);
        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        add_money("silver", 50);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() &&
            query_temp("juxianzhuang_step", ob) == 2){
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        set("inquiry/武林大會", (: ask_wldh :));
        set("inquiry/聚賢莊", (: ask_wldh :));

        //say( "段正淳說道：呵呵，這位" + RANK_D->query_respect(ob) + "，好久不見了啊，近來可好？來我大理有事嗎？\n");
        command("say 呵呵，這位" + RANK_D->query_respect(ob) + "，好久不見了啊，近來可好？來我大理有事嗎？\n");
        return;
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("nod");
        command("say 我就收下你，望你好好學習我段家武技，將來有所作為。");
        command("recruit "+query("id", ob));
        return;
}

mixed ask_wldh()
{
        object me = this_player();

        if( (int)query_temp("in_speech")
         || query_temp("juxianzhuang_step", me) != 2 )
                return notify_fail("段正淳很迷惑的看了看你。。。\n");

        set_temp("in_speech", 1);
        remove_call_out("say_msg");
        call_out("say_msg", 1, me, 1);
        return CYN"原來你是為了聚賢莊武林大會的事情而來的。" NOR;
}

int say_msg(object me, int index)
{
        object ob;

        if( environment() != environment(me) )
                return 0;

        switch( index ) {
        case(1):
                message_vision(CYN"$N說道：你什麼都不用說了，我是不會去參加這所謂的“正義”之舉的。\n"NOR, this_object(), me);
                break;
        case(2):
                message_vision(WHT"<$N皺了皺眉，臉色微微發青。>\n"NOR, this_object(), me);
                break;
        case(3):
                message_vision(CYN"$N說道：江湖上的流言蜚語我聽的多了，從來沒聽過這麼離譜的，喬峰是一個有擔當，有責任的大英雄，大俠士。\n"NOR, this_object(), me);
                break;
        case(4):
                message_vision(CYN"$N說道：我覺得這件事情裡面肯定有什麼誤會，所謂的殺父、殺母、殺師的事情一定不是喬峰乾的，是有人在陷害他。\n"NOR, this_object(), me);
                break;
        case(5):
                message_vision(CYN"$N說道：喬峰是譽兒的結拜兄弟，是阿朱的知己，又是我的救命恩人，喬峰是契丹人又如何？契丹人難道沒有英雄好漢？\n"NOR, this_object(), me);
                break;
        case(6):
                message_vision(CYN"$N說道：大理願與喬峰共同進退。所以我有兩件事情，請你幫忙。\n"NOR, this_object(), me);
                break;
        case(7):
                message_vision(CYN"$N說道：第一件事，是把這封信送給徐長老。我在信中已經說明了我不去參加聚賢莊武林大會的理由。\n"NOR, this_object(), me);
                message_vision(WHT"$N拿出一封信交給了$n。\n"NOR, this_object(), me);
                ob = new("/clone/misc/letter");
                set("long", "這是一封"+this_object()->name()+"寫給徐長老的親筆信函。\n", ob);
                set("send_to", "xuzhanglao", ob);
                set("send_from",query("id",  me), ob);
                set("send_from_name", me->name(), ob);
                ob->move(me, 1);
                break;
        case(8):
                message_vision(CYN"$N說道：第二件事，是請你找機會進入聚賢莊，以喬峰的性格，他一定會在聚賢莊出現的，喬峰現在被千夫所指，一定很需要幫忙。\n"NOR, this_object(), me);
                set_temp("juxianzhuang_step", 3, me);
                break;
        default:
                delete("inquiry/武林大會");
                delete("inquiry/聚賢莊");
                delete_temp("in_speech");
                return 1;
        }
        remove_call_out("say_msg");
        call_out("say_msg", 0, me,++index);
        return 1;
}

mixed ask_skill1()
{
        object me;

        me = this_player();
        if( query("can_perform/qiantian-zhi/zhi", me) )
                return "你不是已經學會了麼？還有什麼疑問？";

        if( query("family/family_name", me) != query("family/family_name") )
                return "你又不是我們段家的傳人，這話是什麼意思？";

        if (me->query_skill("qiantian-zhi", 1) < 1)
                return "你連乾天指法都沒學，還談什麼絕招可言？";

        if( query("family/gongji", me)<50 )
                return "你在族裡碌碌無為，叫我如何信得過你？";

        if (me->query_skill("force") < 100)
                return "你內功的修為還不夠，練高了再來吧。";

        if( query("max_neili", me)<500 )
                return "你的內力修為還不夠，練高點再來吧。";

        if (me->query_skill("qiantian-zhi", 1) < 80)
                return "你的乾天指法功力還不夠，練高了再說吧。";

        message_sort(HIY "\n$n" HIY "點了點頭，將$N" HIY "招至身邊，在"
                     "$N" HIY "耳旁低聲細說良久，$N" HIY "一邊聽一邊不"
                     "住的點頭，看樣子大有所悟。\n\n" NOR,
                     me, this_object());

        command("nod");
        command("say 這招很簡單，稍加練習便成。");
        tell_object(me, HIC "你學會了「乾陽神指」。\n" NOR);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("qiantian-zhi"))
                me->improve_skill("qiantian-zhi", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        set("can_perform/qiantian-zhi/zhi", 1, me);
        addn("family/gongji", -50, me);

        return 1;
}


mixed ask_skill2()
{
        object me;

        me = this_player();
        if( query("can_perform/wuluo-zhang/bian", me) )
                return "你不是已經學會了麼？還有什麼疑問？";

        if( query("family/family_name", me) != query("family/family_name") )
                return "你又不是我們段家的傳人，這話是什麼意思？";

        if (me->query_skill("wuluo-zhang", 1) < 1)
                return "你連五羅輕煙掌都沒學，還談什麼絕招可言？";

        if( query("family/gongji", me)<150 )
                return "你在族裡碌碌無為，叫我如何信得過你？";

        if (me->query_skill("force") < 100)
                return "你內功的修為還不夠，練高了再來吧。";

        if( query("max_neili", me)<500 )
                return "你的內力修為還不夠，練高點再來吧。";

        if (me->query_skill("wuluo-zhang", 1) < 100)
                return "你的五羅輕煙掌還不夠，練高了再說吧。";

        message_sort(HIY "\n$n" HIY "微微一笑，當下更不答話，伸出右掌輕輕"
                     "一抖，登時化出五道掌影，輕飄飄的拍了出去，卻聽“噗噗"
                     "噗”幾聲，$n" HIY "掌影激起的勁風竟在$N" HIY "周圍的"
                     "地面印出了五個手印。\n\n" NOR, me, this_object());

        command("say 看懂了麼？");
        tell_object(me, HIC "你學會了「風雲變幻」。\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("wuluo-zhang"))
                me->improve_skill("wuluo-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        set("can_perform/wuluo-zhang/bian", 1, me);
        addn("family/gongji", -150, me);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();
        if( query("can_perform/jinyu-quan/man", me) )
                return "你不是已經學會了麼？還有什麼疑問？";

        if( query("family/family_name", me) != query("family/family_name") )
                return "你又不是我們段家的傳人，這話是什麼意思？";

        if (me->query_skill("jinyu-quan", 1) < 1)
                return "你連金玉拳法都沒學，還談什麼絕招可言？";

        if( query("family/gongji", me)<150 )
                return "你在族裡碌碌無為，叫我如何信得過你？";

        if (me->query_skill("force") < 100)
                return "你內功的修為還不夠，練高了再來吧。";

        if( query("max_neili", me)<500 )
                return "你的內力修為還不夠，練高點再來吧。";

        if (me->query_skill("jinyu-quan", 1) < 80)
                return "你的金玉拳法還不夠，練高了再說吧。";

        message_sort(HIY "\n$n" HIY "點了點頭，將$N" HIY "招至身邊，在"
                     "$N" HIY "耳旁低聲細說良久，$N" HIY "一邊聽一邊不"
                     "住的點頭，看樣子大有所悟。\n\n" NOR,
                     me, this_object());

        command("nod");
        command("say 好了，你自己去練吧。");
        tell_object(me, HIC "你學會了「金玉滿堂」。\n" NOR);
        if (me->can_improve_skill("cuff"))
                me->improve_skill("cuff", 1500000);
        if (me->can_improve_skill("jinyu-quan"))
                me->improve_skill("jinyu-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        set("can_perform/jinyu-quan/man", 1, me);
        addn("family/gongji", -150, me);

        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();
        if( query("can_perform/duanjia-jian/jing", me) )
                return "你不是已經學會了麼？還有什麼疑問？";

        if( query("family/family_name", me) != query("family/family_name") )
                return "你又不是我們段家的傳人，這話是什麼意思？";

        if (me->query_skill("duanjia-jian", 1) < 1)
                return "你連段家劍法都沒學，還談什麼絕招可言？";

        if( query("family/gongji", me)<300 )
                return "你在族裡碌碌無為，叫我如何信得過你？";

        if( query("shen", me)<0 )
                return "算了吧，傳你絕招只怕你又去作惡！";

        if (me->query_skill("force") < 120)
                return "你的內功的修為不夠，練高了再來吧。";

        if( query("max_neili", me)<800 )
                return "你的內力修為還不夠，練高點再來吧。";

        if (me->query_skill("duanjia-jian", 1) < 80)
                return "你的段家劍法還不行，練練再說吧！";

        message_sort(HIY "\n$n" HIY "點了點頭，沉聲道：“我這就給你演示"
                     "一遍，可看清楚了！”說罷只見$n" HIY "拔出腰間長劍"
                     "，深吸一口氣，腳下步步進擊，穩重之極，手中長劍使得"
                     "猶如飛龍一般，纏繞向$N" HIY "。招式之巧妙，實乃$N"
                     HIY "前所未聞。\n\n" NOR, me, this_object());

        command("haha");
        command("say 招式已經傳你了，你自己練去吧。");
        tell_object(me, HIC "你學會了「驚天一劍」。\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("duanjia-jian"))
                me->improve_skill("duanjia-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        set("can_perform/duanjia-jian/jing", 1, me);
        addn("family/gongji", -300, me);

        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();
        if( query("can_perform/duanjia-jian/lian", me) )
                return "你不是已經學會了五絕劍麼？你要是有疑問我可答不了你。";

        if( query("family/family_name", me) != query("family/family_name") )
                return "你又不是我們段家的傳人，這是什麼意思？";

        if( query("shen", me)<0 )
                return "算了吧，傳你絕招只怕你又去作惡！";

        message_vision(CYN "$n" CYN "對$N" CYN "苦笑兩聲道：我"
                       "武功學得也不好，你還是問問皇兄吧！\n" NOR,
                       me, this_object());

        return 1;
}

mixed ask_skill6()
{
        object me;

        me = this_player();
        if( query("can_perform/duanjia-jian/ailao", me) )
                return "你不是已經學會了麼？還有什麼疑問？";

        if( query("family/family_name", me) != query("family/family_name") )
                return "你又不是我們段家的傳人，這話是什麼意思？";

        if (me->query_skill("duanjia-jian", 1) < 1)
                return "你連段家劍法都沒學，還談什麼絕招可言？";

        if( query("family/gongji", me)<500 )
                return "你在族裡碌碌無為，叫我如何信得過你？";

        if( query("shen", me)<0 )
                return "算了吧，傳你絕招只怕你又去作惡！";

        if (me->query_skill("force") < 200)
                return "你的內功的修為不夠，練高了再來吧。";

        if( query("max_neili", me)<1500 )
                return "你的內力修為還不夠，練高點再來吧。";

        if (me->query_skill("duanjia-jian", 1) < 150)
                return "你的段家劍法還不行，練練再說吧！";

        message_sort(HIY "\n$n" HIY "點了點頭，沉聲道：“我這就給你演示"
                     "一遍，可看清楚了！”說罷只見$n" HIY "拔出腰間長劍"
                     "劍法突變，劍氣縱橫，上六劍，下六劍，前六劍，後六劍"
                     "，左六劍，右六劍，三十六路劍法瞬間完成。\n\n" NOR, me, this_object());

        command("haha");
        command("say 招式已經傳你了，你自己練去吧。");
        tell_object(me, HIC "你學會了「哀牢山劍意」。\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("duanjia-jian"))
                me->improve_skill("duanjia-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        set("can_perform/duanjia-jian/ailao", 1, me);
        addn("family/gongji", -500, me);

        return 1;
}


mixed ask_skill7()
{
        object me;

        me = this_player();
        if( query("can_perform/duanjia-jian/yiyang", me) )
                return "你不是已經學會了麼？還有什麼疑問？";

        if( query("family/family_name", me) != query("family/family_name") )
                return "你又不是我們段家的傳人，這話是什麼意思？";

        if (me->query_skill("duanjia-jian", 1) < 1)
                return "你連段家劍法都沒學，還談什麼絕招可言？";

        if( query("family/gongji", me)<800 )
                return "你在族裡碌碌無為，叫我如何信得過你？";

        if( query("shen", me)<0 )
                return "算了吧，傳你絕招只怕你又去作惡！";

        if (me->query_skill("force") < 300)
                return "你的內功的修為不夠，練高了再來吧。";

        if( query("max_neili", me)<1000 )
                return "你的內力修為還不夠，練高點再來吧。";

        if (me->query_skill("duanjia-jian", 1) < 120)
                return "你的段家劍法還不行，練練再說吧！";

        message_sort(HIY "\n$n" HIY "點了點頭，沉聲道：“我這就給你演示"
                     "一遍，可看清楚了！”說罷只見$n" HIY "拔出腰間長劍"
                     "凝神運氣，把一陽指指力灌注到長劍上，長劍變得金白"
                     "。\n\n" NOR, me, this_object());

        command("haha");
        command("say 招式已經傳你了，你自己練去吧。");
        tell_object(me, HIC "你學會了「一陽劍氣」。\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("duanjia-jian"))
                me->improve_skill("duanjia-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        set("can_perform/duanjia-jian/yiyang", 1, me);
        addn("family/gongji", -800, me);

        return 1;
}

// skybook
mixed ask_duanyu()
{
        object me;
        
        me = this_player();
        if( me->query_condition("killer") )
        {
                command("fear"+query("id", me));
                return "小兒和中原官府應該沒有半點關係，"+RANK_D->query_respect(me) +"還是自我小心通緝！";
        }
        
        if( !query(QUESTDIR1+"start", me) && !query(QUESTDIR2+"start", me) )
        { 
                message_vision(HIC"$N臉上露出氣憤的神色。\n", this_object());
                command("heng");

                // 如果激活了天書任務，設定標誌
                if( query(QUESTDIR+"active", me) )
                { 
                        set(QUESTDIR+"time",time(),me);
                        set(QUESTDIR+"combat_exp",query("combat_exp",me),me);       
                        set(QUESTDIR1+"start",1,me);
                        set_temp(QUESTDIR1+"start",1,me);
                        set_temp("skybook/busy",1,me); // 與任務系統衝突標誌
                        
                        log_file("skybook/TLBB", sprintf("%s(%s) 開始天龍八部第一部分。經驗：%d。\n", me->name(1),query("id",me), query("combat_exp",me)) );
                        command("say 小兒不愛學武，和我吵了幾句就離家出走了，唉......家門不幸啊！");
                        SKYBOOK_D->check_skybook(me, "天龍八部");
                        return 1;
                }
        }
        
        if( query(QUESTDIR1+"start",me) && !query(QUESTDIR1+"wuliangover",me)&& !query(QUESTDIR1+"over",me) )
        {
                message_vision(HIC"$N臉上露出氣憤的神色。\n", this_object());
                command("sigh");
                command("shrug "+query("id",me));
                
                command("say 前段時間有人說在無量山附近看到小兒，不知道現在身在何處。");
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        
        if( query(QUESTDIR1+"start",me) && query(QUESTDIR1+"wuliangover",me)&& !query(QUESTDIR1+"over",me))
        {
 
                command("sigh");
                message_vision(HIC"$N臉上露出擔心的神色。\n", this_object());
                //時間一天
                if( query(QUESTDIR+"time", me) && time()-query(QUESTDIR+"time",me) < 86400 )
                {
                        if( random(2) ) return "今天很忙了，"+RANK_D->query_respect(me) +"先行休息去吧！";
                        else return "譽兒這幾天就可能回來了，"+RANK_D->query_respect(me) +"先行休息去吧！";
                }
                set_temp(QUESTDIR1+"2_start",1,me);

                command("say 小兒日前被四大惡人的南海鱷神擄走了，我們正在設法營救他，有來報目前就在無量山附近的一座石屋內。");
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        
        if( query(QUESTDIR1+"start",me)&& query_temp(QUESTDIR1+"2_start",me) && !query_temp(QUESTDIR1+"yingjiu",me)&& !query(QUESTDIR1+"over",me) )
        {
                command("sigh");
                message_vision(HIC"$N臉上露出擔心的神色。\n", this_object());
                command("shrug "+query("id", me));
                command("say 剛有探報，小兒確實就在無量山附近的一座石屋內，不得已只怕要走一次了。");
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        
        if( query(QUESTDIR1+"start", me) && query_temp(QUESTDIR1+"yingjiu", me)&& !query(QUESTDIR1+"over",me) )
        {
                command("sigh");
                command("look "+query("id",me));
                command("nod "+query("id",me));
                message_vision(HIC"$n向$N表示真誠的感謝。\n", me, this_object());
                command("say 剛有探報，小兒確實就在無量山附近的一座石屋內，不過，有"+RANK_D->query_respect(me) +"相助，料無大礙。");
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        
        if( query(QUESTDIR1+"start", me) && query(QUESTDIR1+"over", me)&& !query(QUESTDIR2+"start", me) )
        {
                command("thank "+query("id", me));
                message_vision(HIC"$n向$N表示真誠的感謝。\n", me, this_object());
                command("say 多謝"+RANK_D->query_respect(me) +"搭救小兒，只是這萬劫谷之後，身體一直不調，才被送往天龍寺求救去了。");
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        
        if( query(QUESTDIR2+"start", me) && !query(QUESTDIR2+"over", me)&& !query_temp(QUESTDIR2+"caught",me) )
        {
                command("sigh "+query("id", me));
                command("say 小兒自萬劫谷回來，總是氣血不定，內力怪異，才被送往天龍求救去了。");
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        
        if( query(QUESTDIR2+"start", me) && !query(QUESTDIR2+"over", me) )
        {
                command("sigh");
                command("say 竟然惹出鳩摩智這等高手，但願小兒吉人天相啊。");
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        command("nod "+query("id", me));
        return "段譽正是犬子，不知道找他何事。";
}

mixed rescue_duanyu()
{
        object me;
        object *obj;
        int i, j;
        
        i =random(5)+2;
        j =random(4)+3;
        me=this_player();

        if( !query(QUESTDIR1+"start", me) )
        {
                command("?");
                return "小兒向來只愛佛法已經，平易近人，援救之說何來之說？";
        }
        
        if( query(QUESTDIR1+"start", me) && !query(QUESTDIR1+"wuliangover", me) && !query(QUESTDIR1+"over", me) )
        {
                command("shrug "+query("id", me));
                command("say 前段時間有人說在無量山附近看到小兒，這等貪玩，就讓他去吧。");
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        
        if( query(QUESTDIR1+"start", me) && query(QUESTDIR1+"wuliangover", me) && !query_temp(QUESTDIR1+"2_start", me) && !query(QUESTDIR1+"over", me) )
        {
                command("sigh");
                command("say 小兒最近收了個莫名其妙的弟子，好像叫什麼南海鱷魚？我總是擔心啊，千萬不要出什麼亂子。");
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        
        if( query(QUESTDIR1+"start", me) && query_temp(QUESTDIR1+"2_start", me) && !query_temp(QUESTDIR1+"yingjiu", me) && !query(QUESTDIR1+"over", me) )
        {
                if( query("shen", me)<0 )
                        return ("我看" + RANK_D->query_respect(me) +"面帶陰邪之氣，恐怕是四大惡人一夥的奸細。");
                if( query("combat_exp", me)<1500000 )
                           return ("四大惡人都是絕頂高手,"+RANK_D->query_respect(me) +"似乎武功不夠，和四大惡人相鬥會有性命之憂。");
                set_temp(QUESTDIR1+"step", i, me);
                set_temp(QUESTDIR1+"steps", j, me);
                command("look "+query("id", me));
                //增加時間和經驗間隔限制
                //時間一天
                if( query(QUESTDIR+"time", me) && time()-query(QUESTDIR+"time", me)<86400 )
                {
                        if(random(2)) return "今天很忙了，"+RANK_D->query_respect(me) +"先行休息去吧！";
                        else return "譽兒被那四大惡人擒走，這件事還需從長計議，"+RANK_D->query_respect(me) +"千萬不得魯莽。";
                }
                //考慮很多限制，這裡經驗差距變得少一點
                if( query(QUESTDIR+"combat_exp", me) && query("combat_exp", me)-query(QUESTDIR+"combat_exp", me)<100000 )
                        return "以"+RANK_D->query_respect(me) +"目前的經驗就算目前有情況，也幫不上什麼忙，還是抓緊練功吧！";

                //設定標誌
                set(QUESTDIR+"time", time(), me);
                set(QUESTDIR+"combat_exp",query("combat_exp",  me), me);
                command("touch "+query("id", me));
                set_temp(QUESTDIR1+"yingjiu", 1, me);
                set_temp("skybook/busy", 1, me);//與任務系統衝突標誌
                
                log_file("skybook/TLBB",sprintf("%s(%s)開始準備營救段譽（第一章）。經驗：%d。\n",me->name(1),query("id", me),query("combat_exp", me)));
                
                message_vision("$N說道：既然"+ RANK_D->query_respect(me) +"有意相助，定會如虎添翼。居我得知，譽兒被四大惡人之首\n"+
                        "段延慶囚在正在無量山附近的一座石屋內，只是路上十分險惡，之前為了探明路線，\n"+
                        "我已損失好幾名手下。你先去大理北面去無量山路上的一個小溪那裡，向北行五里，\n"+
                        "再向西行"+chinese_number(j)+"裡，再向北行"+chinese_number(i)+"裡，然後會到一座高山，再往後就要見機行事了。\n\n"+
                        "$N接著說道：好了，準備一下，為了不驚動對方，切記要在晚上行動，路上小心。\n", me, this_object());
                
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        
        if( query(QUESTDIR1+"start", me) && query_temp(QUESTDIR1+"yingjiu", me) && !query(QUESTDIR1+"over", me) )
        {
                command("look "+query("id", me));
                command("touch "+query("id", me));
                command("say 有"+RANK_D->query_respect(me) +"相助，料無大礙。");
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        
        if( query(QUESTDIR1+"start", me) && query(QUESTDIR1+"over", me) && !query(QUESTDIR2+"start", me) )
        {
                command("thank "+query("id", me));
                command("say 多謝"+RANK_D->query_respect(me) +"搭救小兒，只是這萬劫谷之後，身體一直不調，才被送往天龍寺求救去了。");
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        
        if( query(QUESTDIR2+"start", me) && !query(QUESTDIR2+"over", me) && !query_temp(QUESTDIR2+"caught", me) )
        {
                command("sigh "+query("id", me));
                command("say 小兒自萬劫谷回來，總是氣血不定，內力怪異，才被送往天龍求救去了。");
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        
        if( query(QUESTDIR2+"start", me) && !query(QUESTDIR2+"over", me) )
        {
                command("sigh "+query("id", me));
                command("look "+query("id", me));
                command("say 竟然惹出鳩摩智這等高手，但願小兒吉人天相啊。");
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        
        command("nod "+query("id", me));
        return "小兒向來只愛佛法已經，平易近人，援救之說何來之說？";
}

mixed ask_jiumozhi()
{
        object me;
        
        me = this_player();
        
        if( query(QUESTDIR1+"over", me) && !query(QUESTDIR2+"start", me) )
        {
                command("nod "+query("id", me));
                return "聽說，大輪寺第一高僧鳩摩智將來我天龍寺佛法交流，真是我大理之幸啊。";
        }
        
        if( query(QUESTDIR2+"start", me) && !query(QUESTDIR2+"over", me) )
        {
                command("sigh");
                command("? "+query("id", me));
                command("say 這魔僧竟然如此欺負我大理無人，妄為吐蕃國第一佛法高僧，所謂口生蓮花，全是一派胡言。");
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        
        if( query(QUESTDIR2+"start", me) && query(QUESTDIR2+"over", me) )
        {
                command("nod "+query("id", me));
                return "鳩摩智妄為西域第一佛法高僧，所謂口生蓮花，全是一派胡言。";
        }
        
        command("nod");
        return "大輪明王鳩摩智是吐蕃國的護國法王，但聽說他具大智慧，精通佛法，想來武功也是驚人。";
}

mixed rescue_xiaofeng()
{
        object me;
        
        me = this_player();
        if( !query(QUESTDIR3+"start", me) )
        {
                command("hoho");
                return "江湖人稱南慕容、北蕭峰，端得一條好漢，何來援救之說。";
        }
        
        if( query(QUESTDIR3+"start", me) && !query(QUESTDIR3+"over", me) )
        {
                command("sigh");
                command("shrug "+query("id", me));
                return "聽說這件事情，只是涉及到大遼與大宋之爭，實在不好插手。";
        }

        if( query(QUESTDIR3+"bad", me) )
        {
                command("heng");
                command("? "+query("id", me));
                return "蕭峰，難不是你所迫出中原，今日所謂搭救不知何意。";
        }
        
        if( query(QUESTDIR3+"start", me) && query(QUESTDIR3+"over", me) && !query(QUESTDIR4+"start", me) )
        {
                command("sigh");
                command("shrug "+query("id", me));
                return "聽說這件事情，只是涉及到大遼與大宋之爭，實在不好插手。";
        }
        
        if( query(QUESTDIR4+"start", me) && !query(QUESTDIR4+"over", me) )
        {
                command("nod "+query("id", me));
                command("say 蕭峰乃小兒之義兄，自然要救。這位"+RANK_D->query_respect(me) +"可先行一步，大理段家弟子隨後援到。");
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        
        if( query(QUESTDIR4+"start", me) && query(QUESTDIR4+"over", me) )
        {
                command("haha "+query("id", me));
                return "這一戰真是痛快，"+query("name", me)+"更是威震武林，端得厲害啊。";
        }
        
        return "江湖人稱南慕容、北蕭峰，端得一條好漢，何來援救之說。";
}

mixed help_tianlong()
{
        object me;
        
        me = this_player();
        if( !query(QUESTDIR1+"over", me) )
        {
                command("haha");
                return "天龍寺是我段家武學的最高之地，高手眾雲，請不要危言聳聽。";
        }
        
        if( query(QUESTDIR1+"over", me) && !query(QUESTDIR2+"start", me) )
        {
                command("nod "+query("id", me));
                command("say 聽說，大輪寺高僧鳩摩智不日將來我天龍寺，不知是喜是禍。");
                return 1;
        }
        
        if( query(QUESTDIR2+"start", me) && !query(QUESTDIR2+"over", me) )
        {
                command("sigh");
                command("say 這魔僧竟然如此欺負我大理無人，妄為吐蕃國第一佛法高僧。");
                SKYBOOK_D->check_skybook(me, "天龍八部");
                return 1;
        }
        
        if( query(QUESTDIR2+"over", me) )
        {
                command("thank "+query("id", me));
                return "多謝"+RANK_D->query_respect(me) +"化解這場天龍危機，還將我侄子得以解救。";
        }
        command("hoho");
        return "天龍寺是我段家武學的最高之地，高手眾雲，請不要危言聳聽。";
}

/*
void unconcious()
{
        die();
}
*/