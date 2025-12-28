// This program is a part of NITAN MudLIB 
// redl 2012/11/1 
inherit NPC;
#include <ansi.h>
int ask_makesan();
int ask_begdan();

void add_dan()
{
        set("guiyuan_dan", 1);
        call_out("add_dan", 3600);//每小時能領1顆臨寂歸元丹
}

void create()
{
        set_name(NOR "沈芝毓" NOR, ({ "shen zhiyu","shen" }) );
        set("title", HIG"秘藥師"NOR);
        set("nickname", HIM "化樂天女" NOR);
        set("gender", "女性");
        set("age", 25);
        set("long", "她是一個渾身散發著神秘氣息的女人，據說身兼各門曠世的煉藥之術。\n"
                                "只見有朵小小的"+HIR+"血紅花兒"+NOR+"被她纏在纖纖玉指間不停撥弄著...\n");
        set("attitude", "friendly");
        set("str", 21);
        set("con", 19);
        set("int", 36);
        set("dex", 25);
        set("per", 29);
        set("kar", 30);
        set("level",50);
        set("medical_book", 100);
        
        set("max_qi", 100000);
        set("eff_qi", 100000);
        set("qi", 100000);
        set("max_jing", 100000);
        set("eff_jing", 100000);
        set("jing", 100000);
        set("max_neili", 1);
        set("neili", 1);
        set("max_jingli", 1);
        set("jingli", 1);
        

        set("chat_chance", 3);
        set("chat_msg", ({
                        //(: random_move :) , 
                CYN"沈芝毓微笑著說：武當派玉清散的效力甚奇，但服用方法太繁瑣。\n"NOR ,
                CYN"沈芝毓微笑著說：武當派玉清散的效力甚奇，但服用方法太繁瑣。\n"NOR ,
                CYN"沈芝毓微笑著說：武當派玉清散的效力甚奇，但服用方法太繁瑣。\n"NOR ,
                CYN"沈芝毓微笑著說：武當派玉清散的效力甚奇，但服用方法太繁瑣。\n"NOR ,
                CYN"沈芝毓微笑著說：武當派玉清散的效力甚奇，但服用方法太繁瑣。\n"NOR ,
                CYN"沈芝毓嬉笑著說：火煉玉清散之法固是卓絕常理，我水煉之法將之提純卻是更上層樓。\n"NOR ,
                CYN"沈芝毓嬉笑著說：火煉玉清散之法固是卓絕常理，我水煉之法將之提純卻是更上層樓。\n"NOR ,
                CYN"沈芝毓纖指微捻間呢喃道：這麼冷僻的洗象池，薄霜濃霧峰沁雪，此花怎生就結的出？\n"NOR ,
                CYN"沈芝毓蹙眉沉思道：既為故人所鍾，峨眉弟子有求於我時自當照拂一二...\n"NOR ,
        }) );

        set("combat_exp", 300000000);

        set_skill("liandan-shu", 2500);
        
        set("inquiry", ([
                "玉清散"   : (: ask_makesan :),
                "歸元丹"   : (: ask_begdan :),
                "玉清丸"     : "你的水準不夠，把大量的玉清散交給我，我幫你煉煉玉清丸吧。\n"+NOR,
                "煉丹術"     : "我是可以傳授煉丹術(liandan-shu)的，好好學習吧..\n"+NOR,
                "波陀摩"     : "你也知道那種花兒嗎？我可喜歡他了，下次見到幫我摘一朵好嗎？\n"+NOR,
                "麻薯"     : "Hmm..誰告訴你我貪吃的？我可從來不喜歡吃零食的哦！\n"+NOR,
        ]));
        

        setup();
        carry_object("/d/city/npc/cloth/moon-dress")->wear();
        this_object()->apply_condition("die_guard", 999999999);
        set_temp("nopoison", 3, this_object()); 
                add_dan();
}



void fight_ob(object ob)
{
       ob->remove_enemy(this_object());
       this_object()->remove_enemy(ob);
       tell_object(ob,CYN + "沈芝毓用一雙無辜的媚眼望著你，眼淚都快要掉下來了。\n" + NOR + "你趕緊手忙腳亂地停了下來。\n" + NOR); 
       return;
}

int accept_kill(object who)
{
       who->remove_enemy(this_object());
       this_object()->remove_enemy(who);
       return notify_fail(CYN + "沈芝毓對著你眨眨眼，露出神秘的微笑 ... \n" + NOR + "你發現自己怎麼也捨不得下手！\n" + NOR); 
}

int accept_fight(object who)
{
       who->remove_enemy(this_object());
       this_object()->remove_enemy(who);
       return notify_fail(CYN + "沈芝毓對著你眨眨眼，露出神秘的微笑 ... \n" + NOR + "你發現自己怎麼也捨不得下手！\n" + NOR); 
}

int accept_ansuan(object who)
{
       who->remove_enemy(this_object());
       this_object()->remove_enemy(who);
       return notify_fail(CYN + "沈芝毓在遠處對你眨眼，露出神秘的微笑 ... \n" + NOR + "你發現自己怎麼也捨不得下手！\n" + NOR);
}

void receive_damage(string type, int n)
{
        full_self();
        return;
}

void receive_wound(string type, int n)
{
        return;
}

void unconcious()
{
        return;
}

void die(object killer)
{
        return;
}

void eat_mashu()
{
        this_object()->command("set careful");
        set("food", 0, this_object());
        this_object()->command("eat ma shu");
}

int accept_object(object me, object obj)
{
        int amount;
        object obz;
        
        if (me->is_busy())
        {
                tell_object(me,CYN + "沈芝毓掩著嘴吃吃地笑著對你說：你先把你的事兒忙完再說好不？ \n" + NOR); 
                return 0;
        }
        else 
                me->start_busy(3);

        if (query_temp("shenzy/givewan", me))
        {
                tell_object(me,CYN + "沈芝毓掩著嘴吃吃地笑著對你說：別這麼心急好不好？我的寶貝葫蘆忙著呢... \n" + NOR); 
                 return 0;
        }
                
        switch (query("id", obj))
        {                       
         case "ma shu":
            if( stringp(query("food_race", obj)) || !query("food_remaining", obj) ) {
                tell_object(me,CYN "沈芝毓搖頭對你說道：咦..你這是給我的啥玩意兒？\n" NOR); 
                return 0;
                }
            if( query("decay", obj) > 1 ) {
                tell_object(me,CYN "沈芝毓搖頭對你說道：已經變質了，你留著自個兒吃吧。\n" NOR); 
                return 0;
                }
                tell_object(me,CYN "沈芝毓對你嘻嘻笑道：謝謝你這麼有心了。\n" NOR); 
                addn("shenzy/mashu", 1, me);
                obj = new(__DIR__"obj/yuqingb");
                obj->set_amount(1);
        obj->move(me);
        message_vision(YEL + "沈芝毓一揮衣袖拂過$N的手心時悄悄塞入了一顆"+HIB+"藍色小藥丸"+YEL+"。\n" + NOR, me);
        call_out("eat_mashu", 2 + random(6));
                return 1;
         case "yuqing san":
                if (!function_exists("query_amount",obj) || !query("only_do_effect", obj))
                {
                tell_object(me,CYN "沈芝毓搖頭對你說道：咦..你這是給我的啥玩意兒？\n" NOR); 
                return 0;
                }

        if( query("family/master_name", me) != "張三丰" && query("family/family_name", me) != "峨嵋派")
        {
                tell_object(me,CYN "沈芝毓搖頭對你說道：我只幫峨嵋派和武當張真人弟子，你還是回去吧。\n" NOR); 
                return 0;
        }
        
                if( !query("is_alchemy", me) )
                {
                tell_object(me,CYN "沈芝毓搖頭對你說道：你先去平大夫那裡加入煉藥師協會再來找我吧。\n" NOR); 
                return 0;
                }
  
                obz = present("yaoshi zheng", me);
                if( !objectp(obz))
                {
                tell_object(me,CYN "沈芝毓搖頭對你說道：煉藥師協會的平大夫頒發給你的煉藥師證呢？\n" NOR); 
                return 0;
                }
                if (query("level", obz) < 3)//煉藥師證小於3品，即900煉丹術，+sk的裝備不影響
                {
                tell_object(me,CYN "沈芝毓搖頭對你說道：你這煉藥水平也太次了些吧？三品境界以下的庸才別來煩我。\n" NOR); 
                return 0;
                }
                
                amount = obj->query_amount();
                amount /= 1000;
                
                if (amount < 1)
                {
                tell_object(me,CYN "沈芝毓輕蔑地對你說道：這點玉清散太少，還不值得我出手...\n" NOR); 
                return 0;
                }
         
                set_temp("shenzy/givewan", 1, me);
                amount *= 1000;
         
                if (obj->query_amount() > amount)
                {
                        obj->add_amount(- amount);
                        tell_object(me,CYN "沈芝毓對你點頭道：行了，零頭拿回去，馬上兌給你。\n" NOR); 
                        call_out("delay_givewan", 2, me, new(__DIR__"obj/yuqingb"), amount);
                        return 0;//多退少補
                }
                else
                {
                        destruct(obj);
                        tell_object(me,CYN "沈芝毓對你點頭道：好吧，耐心等等，這就兌給你。\n" NOR); 
                        call_out("delay_givewan", 2, me, new(__DIR__"obj/yuqingb"), amount);
                        return 1;
                }
                
         default:
                return 0;
        }
}

void delay_givewan(object me, object obj, int amount)
{
                        obj->set_amount(amount / 1000);
                obj->move(me);
                message_vision(YEL + 
                "沈芝毓一揮腰間佩著的紫金小葫蘆收走了$N的玉清散，\n" + 
                "隨後衣袖拂過$N的手心時悄悄塞入了"+chinese_number(amount / 1000)+"顆"+HIB+"藍色小藥丸"+YEL+"。\n" + NOR, me);

                me->improve_skill("medical", amount * 25);
                me->improve_skill("liandan-shu", amount * 50);//增加煉丹術提高的機會，在目前的遊戲裡實在缺乏，先決條件限制了3品藥師，則為後期大米了，100倍也不過分
                
/*              峨嵋派1000w exp後得到照拂，暫定1包玉清散獲得5點exp，
                現在玉清散的計劃產量大概在24小時1萬包左右，那麼10id每天可得50w exp。鼓勵多建立武當造散大米來提高人氣
                因為峨眉派本來就弱，如果不能轉世，每天多成長50w~200w exp也不算什麼，就不用封頂獎勵等級了！ */
                
        if( query("family/family_name", me) == "峨嵋派" && query("level", me) >= 10 )
        {
                GIFT_D->work_bonus(me, ([ "exp" : amount*5, "pot" : amount ]));
                }
                
                delete_temp("shenzy/givewan", me);
                return;
}



int recognize_apprentice(object me, string skill)
{
        //峨眉無master會1000煉丹術，再此給予900支持，以保證能評上3品藥師
        if (query("family/family_name", me) != "峨嵋派")
        {
        tell_object(me,CYN "沈芝毓向你扮了個鬼臉，嘻嘻一笑：我只想教授峨眉弟子一些煉丹知識哦..\n" NOR); 
        return -1;
        }

        if (skill != "liandan-shu")
        {
        tell_object(me,CYN "沈芝毓陰沉著小臉湊近你問道：你.確信..你想學的..不是煉丹術(liandan-shu)...嗎？\n" NOR); 
        return -1;
        }
        
        if ( me->query_skillo("liandan-shu", 1) >= 450 && query("shenzy/mashu", me)>random(100) && !query("can_make/臨寂歸元丹", me) ) {
        tell_object(me,HIG "沈芝毓悄悄告訴你：如此如此，@*#^@^*#^@##$&**&\n" NOR); 
        tell_object(me,HIG "沈芝毓悄悄告訴你：這般那般，@!&#^%@&*$&#&&@&#@*$!^%@\n" NOR); 
                tell_object(me,YEL "你經過沈芝毓耐心點撥，學會了臨寂歸元丹的製作方法...\n" NOR); 
                set("can_make/臨寂歸元丹", "guiyuan", me);
        }
        
        
        if (me->query_skillo("liandan-shu", 1) >= 900)
        {
        tell_object(me,CYN "沈芝毓你用力拍著你的背，一副「幹得好，你終於出師了！」的奸笑。\n" NOR); 
        return -1;
        }
        return 1;
}


int ask_makesan()
{
    object me = this_player();
    
        if (query("family/family_name", me) != "峨嵋派")
        {
        tell_object(me,CYN "沈芝毓陰沉著小臉湊近你問道：你.確信..真的想知道只有峨嵋弟子該知道的驚天秘密？\n" NOR); 
        return -1;
        }

        if (me->query_skillo("liandan-shu", 1) < 300)
        {
        tell_object(me,CYN "沈芝毓一巴掌拍你腦門上說道：你先好好學習煉丹術吧...\n" NOR); 
        return -1;
        }

        if (query("medical_book") < 1)
    {
                command("say 真是可惜，你來晚了，書我已經借出去了。");
                return -1;
        }
        
        if (query_temp("shenzy/givebook", me))
    {
        tell_object(me,CYN "沈芝毓劈頭給了你一巴掌，嘆道：當我是出版社呢？\n" NOR); 
                return -1;
        }
        
        //開放峨眉能製藥玉清散，分散武當派人數
        addn("medical_book", -1);
        message_vision(CYN "$n翻出一本黃色小冊子遞給$N，叮囑道：唔，你懂的，好好看。\n" NOR, me, this_object());
        new(__DIR__"obj/mbook")->move(me);
        set_temp("shenzy/givebook", 1, me);
        
        return 1;
}

int ask_begdan()
{
    object me = this_player();
    
        if (query("guiyuan_dan") < 1)
    {
                command("say 真是可惜，你來晚了，臨寂歸元丹我已經送出去了。");
                return -1;
        }
        
        if (query("family/family_name", me) != "峨嵋派")
        {
        tell_object(me,CYN "沈芝毓陰沉著小臉湊近你問道：你.確信..真的想知道只有峨嵋弟子該知道的驚天秘密？\n" NOR); 
        return -1;
        }

        if (query("level", me) >= query("level"))
        {
        tell_object(me,CYN "沈芝毓掩著嘴吃吃地笑著對你說：你臉皮怎麼這麼厚，等級比我還高了還到我這裡來蹭東西咧！\n" NOR); 
        return -1;
        }

        addn("guiyuan_dan", -1);
        message_vision(CYN "$n拋給$N一顆淡藍小藥丸，擠眉弄眼道：接好，記得提前吃，千萬別上癮了啊。\n" NOR, me, this_object());
        new("/clone/medicine/guiyuan")->move(me);
        return 1;
}








