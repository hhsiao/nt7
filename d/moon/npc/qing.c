#include <ansi.h>
inherit NPC;
int answer();
int do_leave();
void create()
{
        set_name("青青", ({ "qing qing", "qing" }) );
        set("gender", "女性" );
        set("age", 18);
        
        set("long", @LONG
青青穿著一身淡青色的衣服，就像是春天晴朗的天空，晴空下清澈的湖 
水，湖水中倒映著的遠山，美得神秘而朦朧。青青的腰纖細而柔軟，就 
像是春風中的楊柳。青青的彎刀是用純銀作刀鞘，刀柄上鑲著一粒光澤 
圓潤的明珠。青青的眼波比珠光更美麗，更溫柔。 
LONG
); 
        set("inquiry",([
        "wandao" : (: answer :),
        "圓月彎刀" : (: answer :),
        "彎刀" : (: answer :),
    ]) );
/*    set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        })); */
        set("combat_exp", 1000000);
        set("attitude", "friendly");
        set("finish", 0);
        //set_skill("move", 200);
        set_skill("parry", 250);
        set_skill("blade", 250);
        set_skill("dodge", 250);
        set_skill("moon-blade", 80);
        map_skill("blade", "moon-blade");
        set("reset", 1);
        set("arrive_msg", "有一陣風吹過來，風中彷彿有個影子。一條淡淡的影子，帶著種淡淡的香氣。\n");
        setup();
        carry_object("/obj/armor/cloth",
           ([ "name": "青衫",
                        "long": "淡青色的衣服。\n" ])
                )->wear();
        carry_object(__DIR__"obj/basket")->wield();
        carry_object(__DIR__"obj/wandao");
} 
void init(){
        ::init();
        if(environment(this_object())->query("short") == "玉女峰") {
                remove_call_out("do_leave");    
                call_out("do_leave", 120);
        }
} 
int answer(){
        object stone, me;
        
        me = this_player();
        message_vision("$N看著$n，淺淺地笑了：“你也用刀？”\n", this_object(), me);
        if(environment(this_object())->query("short") == "玉女峰") {
                message_vision("\n$N忽然又轉過頭，若有所思地看著絕壁遠方的一塊青石。\n", this_object());
                message_vision("$N有點遺憾地自語：“忘憂草的葉子每年只長一次，每次只有三片，如果你來 
得遲些，它的葉子就要枯萎了。” \n", this_object());
                environment(this_object())->wang_you();
        }
        return 1;
} 
int xiaolou(object me){
        object obj, petal;
        if(!interactive(me) || environment(me) != environment(this_object())) {
                environment(this_object())->do_leave();
                environment(this_object())->do_leavee();
        }
        obj = present("eagle man", environment(this_object()));
        message_vision("\n$N陰森森的道：“拿來！小樓一夜聽春雨。”\n", obj);
        message_vision("\n$N的臉色變了，忽然拋下了手裡的花藍，握住了那柄彎刀的刀柄。\n",
                        this_object()); 
        petal = new(__DIR__"obj/petal");
        petal->move(environment(this_object()));
        if(obj) {
                obj->wf(me);
   } else {
                environment(this_object())->do_leavee();
                environment(this_object())->do_leave();
        }
} 
int do_killeagle(object me){
        object obj;
        
        message("vision", HIW"\n就在這時候，青青使出了她的刀。刀光飛起時，" 
+ me->name() + HIW"的眼睛已將要合起。\n"NOR, environment(me), me);      
        tell_object(me, HIC"\n似乎看見青青手裡刀光一閃，黑暗中忽然有了光，月光，圓月。\n"NOR); 
        me->unconcious();
        obj = present("eagle man", environment(this_object()));
        message_vision("只見刀光沒入$N的胸前。\n", obj);
        obj->die();
        call_out("check_wake", 5, me);
        return 1;
} 
void check_wake(object me){
        object blade;
        
        if(environment(me) != environment(this_object())){
                set("finish", 1);
                do_leave();
        }
        if(me->query_temp("is_unconcious")){
                remove_call_out("check_wake");
                call_out("check_wake", 3, me);
        } else {
                tell_object(me, "\n你睜開眼，就看見一輪冰盤般的圓月，也看見了青青那雙比月光更美的眼睛。\n"); 
                tell_object(me, "無論是在天上還是在地下，都不會有第二雙這麼美麗的眼睛。\n");
                message_vision("$N守在$n身旁，眼睛裡還閃著淚光。\n", this_object(), me);
                message_vision("\n$N纖手拂過面頰，臉色慢慢變了，連身子都已開始顫抖，忽然道：“我真的在流淚？”\n", 
                                this_object());
                message_vision("$N臉色變得更奇怪，彷彿變得說不出的害怕。$P慢慢地從腰間解下那柄彎彎的刀，\n"
+ "放在$n懷裡。\n", this_object(), me);
                set("finish", 1);
                if(blade = present("moonblade", this_object())){
                        blade->move(me);
                }
           do_leave();
        }
} 
int do_leave(){
//      message_vision("hehe\n", this_object());        
        if(find_call_out("check_wake") == 1) {
                call_out("do_leave", 20);
                return 1;
        }
//      message_vision("ha\n", this_object());
        if(this_object()->query("finish")) {
                message_vision("\n$P慢慢地向後退去，消失在夜幕中。\n", this_object());
                message_vision("輕輕的嘆息聲從幽遠的山谷傳來，如同幽靜的夜裡幽遠的風。。。 \n", this_object());
                destruct(this_object());
        } else {
                message_vision("$N身影一縱，猶如蜻蜓點水在青石上略一停頓就沒入了黑暗之中。\n", this_object());
                destruct(this_object());
        }
        return 1;
 
}
int die(){
        object obj;
        if(present("eagle man", environment(this_object()))){
                environment(this_object())->leavee();
        }
        message_vision("只見一股青煙升起，$N已然失去了蹤影。\n", this_object());
        obj = new(__DIR__"obj/basket");
        obj->move(environment(this_object()));
        destruct(this_object());
        return 1;       
} 
