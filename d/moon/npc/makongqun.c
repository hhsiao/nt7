#include <ansi.h>
inherit "/obj/npc/npcd";
//inherit NPC;
int do_answer(string arg); 
void create()
{
        set_name("馬空群",({"ma kongqun","ma"}));
        set("title",HIW"萬馬堂"+HIR" 堂主"NOR);
        set("long","他端端正正地坐在那裡。就算屋子裡沒有別人的時候，他還是坐得規規矩矩，椅子
後雖然有靠背，他腰幹還是挺得筆直筆直。他一個人孤孤單單地坐在那裡，距離每
個人都那麼遙遠。他彷彿已將自己完全隔絕紅塵外，沒有歡樂，沒有享受。\n");
        set("gender","男性");
        set("age",62);
                
        set("int",22);
        set("cor",300);
        set("cps",60);
        set("str",150);
                set("reward_npc", 1);
       set("difficulty", 20);
   
        set("no_busy",99);
        set_skill("unarmed",500);
        set_skill("dodge",200);
        set_skill("parry",500);
        set_skill("force",220);
        set_skill("move",300); 
        set_skill("tigerstrike",500);
        set_skill("chaos-steps",200);
        
        map_skill("unarmed","tigerstrike");
        map_skill("dodge","chaos-steps");
        
        
        set("force",2500);
        set("max_force",25000);
        set("force_factor",150);
        set("max_atman",20000);
        set("atman",1000);
        set("max_mana",20000);
        set("mana",1000);
        set("combat_exp",50000000);  
        set("attitude", "friendly");
    set("resistance/kee",95);
    set("resistance/sen",95);
    set("resistance/gin",95);
       set("no_death_penalty",1);
  new_npc(this_object(),80000000,1000000,"bandit",1); 
        
        setup();
           carry_object(__DIR__"obj/qblade")->wield();  
        carry_object(__DIR__"obj/bcloth2")->wear();     
    
}    
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_answer","answer");
}  
void greeting(object me)
{
        object ob;
        ob= this_object();
        if( !me || environment(me) != environment() ) return;
        
//      this happens in 書房 only
        
        
        if (environment(ob)->query("wanma_discussion") && !me->query("wanma/殺場主_ma")) {
                message_vision(YEL"$N拿起桌上的酒杯，喝了一口又放下，然後緩緩地說：\n"NOR,ob);  
                call_out("event1",1,me,0);
                return;
        }
        
        if (environment(ob)->query("wanma_discussion") && me->query("wanma/殺場主_ma")
                && me->query_temp("wanma/殺花滿天_ma") && me->query_temp("wanma/殺雲在天_ma")
                && !me->query("wanma/準備殺同夥_ma")) {
                message_vision(CYN"
過了許久，馬空群緩緩地說：“朋友，兄弟，一轉眼就成了想害你的人，
我不怪他們，如果我是他們，我也會這麼做。不過，若是事情敗露，我也
死而無怨。。。。這事你辦得很好，從此，這萬馬堂，一半就是你的了。”\n\n"NOR,ob);    
                message_vision(CYN"
馬空群閉上眼睛，一字字道：“白天羽的孤兒，我們還不知道是誰，這樣
的仇恨，本就是非報不可的，他也一定會來。無論什麼樣的秘密，遲早總
有人知道，不過，他現在一定還沒有抓住真實的證據，能證明是我們下的
手。所以，凡是知道這個秘密的人，都不應該再活著，你看過那張紙片，
你知道該怎麼辦。。。。”\n\n"NOR,ob);   
        message_vision(CYN"
馬空群沉聲道：“我就在這裡等他，等他先錯！”他神情又漸漸冷靜，一
字字慢慢地接著道，“只有等，是永遠不會錯的！一個人只要能忍耐，能
等，遲早總會等得到機會的！”\n\n"NOR,ob);       
                me->set("wanma/準備殺同夥_ma",1);
                destruct(this_object());         
                return;
        }
        
        if (environment(ob)->query("wanma_discussion") && me->query("wanma/準備殺同夥_ma")
                && me->query_temp("wanma/易大經_ma") && me->query_temp("wanma/薛斌_ma")
                && me->query_temp("wanma/桃花娘子_ma") && me->query_temp("wanma/柳東來_ma")
                /*&& me->query_temp("wanma/郭威_ma") */
                && !me->query("wanma/準備殺主腦_ma")) {
                call_out("event2",1,me,0);
                return;
        } 
        if (environment(ob)->query("wanma_discussion") && me->query("wanma/準備殺主腦_ma")
                && me->query_temp("wanma/花白鳳_ma") && me->query_temp("wanma/傅紅雪_ma")
                && me->query_temp("wanma/葉開_ma"))     {
                message_vision(YEL"馬空群一躍而起，大笑道：“經此一役，萬馬堂永垂武林。”\n"NOR,ob);
                message_vision(CYN"馬空群摸著手上的傷痕，“淚可以抹乾，但血，還是要血來洗的！”\n\n\n",ob);
                
                if(!me->query("wanma/終局馬空群")){
                                call_out("imbue_event", 2, me);
                        }
                if(!me->query("m_success/神刀萬馬"))
                {
                        me->set("m_success/神刀萬馬",1);
                        me->add("score",500);
                }
                                
                return;
        }
                
        if (!me->query("wanma/迎賓")) return;
        
        if (me->query("m_success/神刀萬馬")) return;
        
        if (me->query("wanma/上樓")) return;
        
        if (me->query("wanma/殺客人") && me->query_temp("wanma/殺客人a")
                && me->query_temp("wanma/殺客人b") && me->query_temp("wanma/殺客人c")
                && !me->query("wanma/上樓")) {
                message_vision(CYN"
馬空群說：“好，你很有前途，萬馬堂就需要你這樣的人才，如果你願意，
以後你就是我馬空群的朋友。不過，有一個問題要問你，如果你的朋友獨
斷獨行，專橫跋扈，逼著你做不願意做的事，你會不會背棄他？\n",ob);
                tell_object(me,HIY"（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ） \n"NOR);
                me->set_temp("wanma/answer_ma",2);
                return;
        }       
        
        if (me->query("wanma/準備殺刺客_ma") && me->query_temp("wanma/江湖五毒a")
                && me->query_temp("wanma/江湖五毒b") && me->query_temp("wanma/江湖五毒c")
                && me->query_temp("wanma/江湖五毒d") && me->query_temp("wanma/江湖五毒e")
                && !me->query("wanma/殺客人")) {
                message_vision(CYN"
馬空群看著你讚賞地說：“果然沒看錯你，這事辦得很好，江湖五毒惡貫
滿盈，的確該死。你若在他們身上找到什麼重要的東西，可給我一看。”\n"NOR,ob);
                me->set_temp("wanma/give_paper",1);
                return;
        }
        
        if (me->query("wanma/準備殺刺客_ma")) {
                command("say 我要你追查的事有線索了麼？");
                return;
        }
        
       
        message_vision(YEL"$N的目光凝視著遠處，在每個人面前都停留了很久，最後才凝視著$n。\n"NOR,ob,me);
        message_vision(CYN"$N緩緩地說：“真正的勇氣，並不是從刀劍上得來的！勇氣這種東西很奇
怪，你非但看不到，感覺不到，也根本沒有法子證明的，所以一個真正有勇氣
的人，有時在別人眼中看來，反而像是個儒夫。你在鎮上的所為我已經聽說了，
你是否願意替萬馬堂辦一件事，一件需要真正勇氣的事？\n"NOR,ob);
        tell_object(me,HIY"（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ） \n"NOR);
        me->set_temp("wanma/answer_ma",1);
        return;
}   
int do_answer(string arg)
{
        object me,ob;
        
        me=this_player();
        ob=this_object();       
        
   if(me->query_temp("wanma/answer_ma")==1) {
                if(arg=="yes") {
                        message_vision("\n$N堅定地點了點頭說：“叄堂主的事，就是在下的事。”\n"NOR,me);
                        message_vision(CYN"$N說：“好，你一路前來，可曾聽到雞啼大吠之聲？”\n",ob);
                        message_vision(CYN"不待你回答，$N接下去說：“既有人家，必有雞犬，邊城馬場之中，怎麼
會沒有牧大和獵狗？只因此間的叄十八條猛犬，叄百九十叄只雞，都已在一夜
之間，死得乾乾淨淨----被人一刀砍斷了脖子，身首異處而死。雞犬不留，趕
盡殺絕，永絕後患。。。好毒的手段。\n"NOR,ob);
                        message_vision(CYN"    鎮上新近來了許多生人，我想請你去察看，找出可疑之處，拿到證據後來
告訴我。你不是萬馬堂的人，不容易引起兇手的疑心，不過，也需小心謹慎。”\n\n"NOR,ob);
                        message_vision(YEL"說完，馬空群不再看你，又一動不動地陷入了沉思。\n\n"NOR,ob);
                        me->delete_temp("wanma/answer_ma");
                        me->set("wanma/準備殺刺客_ma",1);
                        return 1;       
                }
                if(arg=="no"){
                        message_vision("\n$N趕緊搖了搖頭說：“在下武藝低微，你還是另請高明吧。”\n"NOR,me);
                        message_vision(CYN"$N微微一笑說：“看來你是徒得虛名！送客！”\n"NOR,ob);
                        me->delete_temp("wanma/answer_ma");
                        return 1;
                }
                tell_object(me,"你只能回答ｙｅｓ或ｎｏ。\n");
                return 1;
        }
        if(me->query_temp("wanma/answer_ma")==2) {
                if (arg=="yes" || arg =="no") {
                        if(arg=="yes") {
                                message_vision("\n$N謹慎地說：“這樣的人自然就不是我的朋友了。”\n"NOR,me);
                        }else if (arg=="no") {
                                message_vision("\n$N搖了搖頭說：“無論你的朋友是好還是壞，只要他是你的朋友，你
就不能在背後給他一刀。”\n"NOR,me);
                        }
                        me->delete_temp("wanma/answer_ma");
                        me->set("wanma/上樓",1);
                        message_vision(YEL"\n$N不置可否地一笑：“此處耳目眾多，你可到我書房等候，我自有安排。”\n"NOR,ob);
                        message_vision(YEL"$N轉身離去，不再說話。\n"NOR,ob);
                        destruct(this_object()); 
                        return 1;
                }       
                tell_object(me,"你只能回答ｙｅｓ或ｎｏ。\n");
                return 1;
   }
        
        return 0;
}  
int accept_object(object who, object ob)
{
        if (ob->query("name")=="紙片"){
                if (!who->query_temp("wanma/give_paper")) {
                        message_vision(CYN"$N說：“這種捕風捉影的東西也可當真？”\n"NOR,this_object());
                        return 0;
                } else {
                        message_vision(CYN"
馬空群拿過紙看了看，意味深長地掃了你一眼。正色道：“此事真偽莫辨，
大有蹊蹺。昨夜十八位馬師又遭人暗算，身首異處，萬馬堂戒備森嚴，外
人極難進入。兇手必然就是新請來的幾位客人之一，很可能就是他們和鎮
上的江湖五毒內外勾結，所以我想請你把他們也一併除去。”\n\n"NOR,this_object());
                        tell_object(who,WHT"雖然屋子裡暖洋洋的，一股寒意禁不住從你心底升起。\n\n"NOR);
                        message_vision("$N遲疑了一下，猶猶豫豫地說：“如果殺錯了，怎麼辦？”\n\n"NOR,who);
                        message_vision(CYN"$N微微一笑：“殺錯了，可以再殺。”\n"NOR,this_object());
                        message_vision(YEL"\n$N轉過身去，不再說話。\n"NOR,this_object());
                        who->set("wanma/殺客人",1);
                }
                return 1;
        }       
        return 0;
}  
string *event1_msg=     ({
        CYN"
明人不說暗話，十九年前我刺殺白天羽的那件事，的確做得不夠光明磊落，
但若讓我再回到十九年前，我還是會將同樣的事再做一次，因為白天羽實
已將我逼得無路可走，他非但要我加入他的神刀堂，還要我將家財全部貢
獻給神刀堂，他保證一定能讓我名揚天下。但我到時侯只不過是他手下的
一個傀儡而已，雖然名揚天下又有什麼用。白天羽並不是個卑鄙小人，他
的確是個英雄，他藝才絕豔，雄姿英發，武功之高，已絕不在昔年的上官
金虹之下。但是接近了他之後，就要完全被他指揮支配，就得完全服從他，
想我馬空群又豈是寄人籬下之輩，若想恢復自由，就非殺了他不可！”\n"NOR,
                
CYN"十九年了，沒想到今天他的後人，也就是白天羽和魔教公主的私生子竟然
還活著，此人身份尚不明，但總是心頭一患。。。。。。"NOR, 
        CYN"
馬空群話鋒一轉道：“不過，現在對最大的威脅不是這個，而是來自萬馬
堂內部。你所殺的江湖五毒，以及心懷叵測的慕容明珠等人，都不是白天
羽的後人所僱，而是我最信任的兄弟，雲在天和花滿樓請來的。他們想借
此機會將我趕出萬馬堂取而代之。”\n"NOR, 
CYN"馬空群長嘆一聲：“我的根已在這裡，若有人要我走，我也會死。所以，
無論誰出賣我，都得死。”\n"NOR, 
CYN"“你若是能夠替我除去他們，以後你就是萬馬堂的副堂主。”\n"NOR, 
CYN"“不過，萬馬堂的聲名不能受損，所以除你之外，我不想讓任何人知道是
誰下的手，切記。”\n"NOR, 
YEL"馬空群揮揮手：“我累了，你走吧。辦完此事後再來找我。”\n"NOR,       
        
});  
void event1(object me, int count)
{
        if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
        tell_object(me,event1_msg[count]+"\n");
        if(++count==sizeof(event1_msg))
        {
                message_vision(YEL"馬空群轉過身不再看你。\n\n"NOR,this_object(),me);
                me->set("wanma/殺場主_ma",1);
                destruct(this_object()); 
                return;
        }
        else call_out("event1",1,me,count);
        return ;
}  
string *event2_msg=     ({
        YEL"
馬空群望著窗外，沒有說一句話，許久，許久。。。。\n"NOR, 
YEL"窗外，山坡前一片大草原，接連著碧天。風吹長草，正如海洋中的波浪。\n"NOR, 
CYN"過了很久，馬空群才緩緩道：“現在你看見的是什麼？”\n"NOR, 
CYN"你回答道：“草原、大地。”\n"NOR, 
CYN"馬空群道：“看不看得見這塊地的邊？”\n"NOR, 
CYN"你道：“看不見。”\n"NOR, 
CYN"馬空群道：“這一塊看不見邊際的大地，就是我的！”他神色忽然激動，
大聲接著道：“大地上所有的生命，所有的財產，也全都屬於我！我的根
已長在這塊地裡。”\n"NOR, 
CYN"又過了很久，馬空群的激動才漸漸平息，長嘆道：“無論誰要擁有這一片
大地，都不是件容易事。你知道不知道，這一切我是怎麼樣得來的？”\n"NOR, 
CYN"馬空群突然撕開了衣襟，露出鋼鐵般的胸膛，道：“你再看看這是什麼？”\n"NOR, 
WHT"你看著他的胸膛，呼吸都似已停頓。從未看過一個人的胸膛上，有如此多
刀傷，如此多劍痕！\n"NOR, 
CYN"馬空群神情突又激動，眼睛裡發著光，大聲道：“這就是我付出的代價，
這一切都是用我的血，我的汗，還有我無數兄弟的性命換來的！所以無論
什麼人，都休想將這一切從我手裡搶走——無論什麼人都不行！”\n"NOR, 
CYN"“所以，十九年前，白天羽必須得死，現在，他的孤兒必須得死，他的外
室必須得死，該流的血，一定要流。我已經把這些人的下落打聽確實，那
個孤兒是李尋歡的弟子，他就在這鎮上，那個魔教公主花白鳳，隱藏在萬
馬堂周圍，你仔細搜索一定能找到。至於傅紅雪，是花白鳳用仇恨撫養長
大，他也不能再活下去。”\n"NOR, 
CYN"馬空群緊緊地盯著你說：“只有這些人都不存在了，萬馬堂才能永遠不倒，
你我才能永遠不倒。如果你能完成這最後一個使命，從此，我的就是你的，
我的一身武藝也將傳授於你。”\n"NOR,
        
});  
void event2(object me, int count)
{
        if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
        tell_object(me,event2_msg[count]+"\n");
        if(++count==sizeof(event2_msg))
        {
                message_vision(YEL"“你已經沒有任何其他選擇了，我希望你明白這個道理。”說完，馬空群
便不再看你。。\n\n"NOR,this_object(),me);
                me->set("wanma/準備殺主腦_ma",1);
                destruct(this_object()); 
                return;
        }
        else call_out("event2",1,me,count);
        return ;
}    

void imbue_event(object me){
        object weapon, *inv, obj;
        string prop;
   int i;
        if(!interactive(me) || environment(me) != environment(this_object())) {
                return 0;
        }
        obj = me->query_temp("weapon");
        if(objectp(obj) && obj->query("owner")) {
                weapon = me->query_temp("weapon");
        } else { 
                inv = all_inventory(me);        
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
                                weapon = inv[i];
                                break;
                        }
                }       
        }                       
        if(!objectp(weapon)){
                if(!objectp(obj)){
                        message_vision(HIR"\n血與淚一滴一滴掉落在地上。。。\n"NOR, me);
                } else {
                        message_vision(HIR"\n血與淚一滴一滴掉在$N的" + obj->name() + HIR"上又滑落到地上。\n", me);
                }
        }else {
                message_vision(HIR"\n血與淚一滴一滴掉落在$N的" + weapon->name() + HIR"上，不一會便凝固了。。 \n"NOR,
                                me);
                message_vision(HIR"血淚在" + weapon->name() + HIR"上瀰漫著血腥的味道，但轉瞬間又蒸發無痕。\n"NOR, me);
                if(weapon->query("weapon_prop")) {
                        prop="weapon_prop/";
                }
                if(weapon->query("equipped") == "wielded") {
                        weapon->unequip();
                           weapon->add(prop+"p_str", 100);
                   weapon->wield();
                } else {
                            weapon->add(prop+"p_str", 100);
                }
                weapon->save();                 
                me->set("wanma/終局馬空群", 1);
                 if (me->query("class")=="bandit")
                	if (me->query_skill("tianya-blade",1)<1)
                me->set_skill("tianya-blade", 1);
                me->save();
                return;
        } 
        me->set("wanma/終局馬空群", 2);
        me->save();
                destruct(this_object()); 
        return;
} 
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/殺馬空群", 1);
        }
        
        ::die(); 

}