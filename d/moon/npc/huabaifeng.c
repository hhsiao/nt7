#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";
inherit NPC;
void create()
{
        set_name("花白鳳",({"hua baifeng","hua","baifeng"}));
        set("title",YEL"雙手如雞爪的老婦"NOR);
        set("long","
她臉上蒙著黑紗，黑色的長袍烏雲般散落在地上，只露出一雙乾癟、蒼老、
鬼爪般的手。她雙手合什，喃喃低誦，但卻不是在析求上蒼賜予多福，而
是在詛咒。詛咒著上蒼，詛咒著世人，詛咒著天地間的萬事萬物。\n");
        
        set("gender","女性");
                
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        set("per",1);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("force",1500);
        set("max_force",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",1250000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
                   
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
//      carry_object(__DIR__"obj/gsword")->wield();    
    
} 
void init()
{       
        object me; 
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        } 
          add_action("do_give", "show");
} 
void greeting(object me)
{
        object ob;
        ob=this_object();
        if( !me || environment(me) != environment() ) return;
        if (me->query("wanma/尋地洞") && !me->query("wanma/殺場主_ma")) {
                call_out("event1",1,me,0);      
        }
        if (me->query("m_success/神刀萬馬")) return;
        
        if (me->query("wanma/殺場主_ma")
                && me->query_temp("wanma/殺花滿天_ma") && me->query_temp("wanma/殺雲在天_ma")
                && me->query_temp("wanma/殺公孫斷_ma") && me->query_temp("wanma/殺馬芳玲_ma")
                && me->query_temp("wanma/殺小虎子_ma") 
                && !me->query("wanma/準備殺同夥_ma")) {        
                message_vision(CYN"
花白風點了點頭，她的聲音淒厲、尖銳，如寒夜中的鬼哭，“馬空群，馬
空群，你也有今天！”\n"NOR,ob);
                message_vision(CYN"
花白風說：“下一步，就輪到馬空群的同夥了，我已經知道的有薛斌和易
大經，你要找出其餘的，殺光他們的一家老少。”\n"NOR,ob);
                me->set("wanma/準備殺同夥_ma",1);
        }
        if (me->query("wanma/準備殺同夥_ma") 
                && me->query_temp("wanma/易大經_ma") && me->query_temp("wanma/薛斌_ma")
                && me->query_temp("wanma/桃花娘子_ma") && me->query_temp("wanma/柳東來_ma")
                /*&& me->query_temp("wanma/郭威_ma") */
                && !me->query("wanma/準備殺主腦_ma")) {
                message_vision(CYN"
花白風轉過身去，跪在黑色的神龕前，喃喃低語，沒有人能聽到她在說什麼，
片刻，。。\n"NOR,ob);
                me->set("wanma/準備殺主腦_ma",1);
        }       
        if (me->query("wanma/準備殺主腦_ma") && me->query_temp("wanma/殺馬空群")
                && me->query_temp("wanma/殺丁白雲") ){
                
                message_vision("$N向$n似哭似笑地大喊：終於報了。。。終於報了。。。\n",this_object(),me);
                message_vision("$N轉過身去，再次跪在黑色的神龕前，喃喃低語，沒有人能聽到她在說什麼，。。\n", this_object());
                if(!me->query("wanma/結局_ma")){
                                call_out("imbue_event", 2, me);
                        }
                if(!me->query("m_success/神刀萬馬"))
                {
                        me->set("m_success/神刀萬馬",1);
                        me->add("score",500);
                }
            }
        return;
} 
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
me->set_temp("wanma/花白鳳_ma",1);
        ::die();
}  
string *event1_msg=     ({
        CYN"
花白風冷冷地說：“是三娘指點你到這裡的吧，我不管你的來歷是什麼，
只要你能為神刀堂報了這血海深仇，你就是神刀堂的傳人。”\n"NOR, 
CYN"為了這一天，我已準備了十九年，整整十九年，傅紅雪背叛了我，葉開背
叛了我，他們是背叛了神刀堂幾十條屈死的冤魂！！！”\n"NOR, 
CYN"她的聲音裡充滿了一種神秘的自信，彷彿已融入了天上地下所有神魔惡鬼
的詛咒。”\n"NOR, 
CYN"你要記住，從此以後，你就是神，復仇的神！無論你做什麼，都用不著後
悔，無論你怎麼樣對他們，都是應當的！”\n"NOR, 
CYN"“不過，我絕不會讓馬空群死得太快，太容易，我要你先去殺了他的手下，
他的兒子女兒，讓他嚐嚐家破人亡的滋味。\n"NOR, 
});  
void event1(object me, int count)
{
        if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
        tell_object(me,event1_msg[count]+"\n");
        if(++count==sizeof(event1_msg))
        {
                message_vision(CYN"花白風突又揮刀，一刀插入$N面前的土地上，厲聲說道：“快走，用這把
刀將他們的頭全都割下來，再回來見我，否則非但天要咒你，我也要咒你！\n\n\n"NOR,me);
                me->set("wanma/殺場主_ma",1);
                return;
        }
        else call_out("event1",1,me,count);
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
                        message_vision(HIC"\n咒語迷霧般纏繞著整個空間。。。\n"NOR, me);
                } else {
                        message_vision(HIC"\n咒語迷霧般纏繞著$N的" + obj->name() + HIC"上，然後再蒸騰，煥發。\n", me);
                }
        }else {
                message_vision(HIC"\n咒語迷霧般纏繞著$N的" + weapon->name() + HIC"上，一瞬間，讓人恍然大悟。。。 \n"NOR,
                                me);
                message_vision(HIC"整個空間的力量似乎都集中在" + weapon->name() + HIC"上，但一下子就把所有的愛、恨、情、仇，一併帶走。。。\n"NOR, me);
                if(weapon->query("weapon_prop")) {
                        prop="weapon_prop/";
                }
                if(weapon->query("equipped") == "wielded") {
                        weapon->unequip();
            
                         weapon->add(prop+"p_int", 10);
                   weapon->wield();
                } else {
          weapon->add(prop+"p_int", 10);
        }
                weapon->save();                 
                me->set("wanma/結局_ma", 1);
                if (me->query("class")=="bandit")
                	if (me->query_skill("tianya-blade",1)<1)
                me->set_skill("tianya-blade", 1);
                me->save();
                return;
        } 
        me->set("wanma/結局_ma", 2);
        me->save();
        return;
} 

int do_give(string arg){
        object ob,me,obj,rune;
        int i, j;
        string longarg,acceptor,objectname;
        mapping data, data2,spe_data, ench;
        string  *apply;
        
        obj = this_object();
        me = this_player();
      if (!arg) return 1;  
    if( sscanf(arg, "%s to %s", objectname, acceptor)==2 ){ 
        if(acceptor!="花白鳳"&&acceptor!="hua baifeng"&&acceptor!="hua")
                return 1;
        if(obj->query("busy"))
        	return notify_fail("花白鳳正在和別人說話，你稍等一下吧。\n");
        ob=present(objectname,me);
        if(!objectp(ob)) return 1;
if(!ob->query("changed"))
	return notify_fail("這東西花白鳳是看不上的。\n");
	if (!ob->query("weapon_prop"))
			return notify_fail("花白鳳只能幫你詛咒武器。\n");
			  if( ob->query("equipped") )
      return notify_fail("你必須放下這樣東西才能進行詛咒。\n");
      
      if (!me->query("wanma/結局_ma"))
      	      return notify_fail("只有魔教傳人才可以進行詛咒。\n");
      	      i = me->query("for_practice_modao");
      	      if (i<3) i =3;
  message_vision(HIC"\n咒語迷霧般纏繞著整個空間。。。\n"NOR, me);
     message_vision(HIC"\n咒語迷霧般纏繞著$N的" + ob->name() + HIC"上，一瞬間，讓人恍然大悟。。。 \n"NOR,
                                me);
                message_vision(HIC"整個空間的黑暗似乎都集中在" + ob->name() + HIC"上，但一下子就把世間的黑暗全部帶來，那麼的陰冷，恐懼。。。\n"NOR, me);
            ob->set("for_modao",i);
            ob->save();
			} 
			return 1;
}