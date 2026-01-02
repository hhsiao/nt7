/*********************************************************
   本文件只被 hj_room1.c 使用。

   本房間描述帶有圖片，建議效果（即奈何所使用設置）：
   zmud4.62 32bit 漢化版， 宋體，小四(12)或小五(10) 查看，
   可得最佳效果。

   本房間支持兩個 JOB。

   其一，殺了各族的族長時，可隨機得到該族的權杖，蒐集所有
         族的權杖，再回來這裡發呆 JOB1_NEED_IDLE 秒，即可
         得到大量獎勵。

   其二，在此發呆 JOB2_NEED_IDLE 秒，即得到 幽靈武士 JOB。
         殺了它可以得到額外的獎勵。若被其他人殺去，與普通
         各族的NPC效果一樣。本人殺了幽靈族武士時，可得到
         技能提升與遊戲得分。

   JOB1 的發呆生效時間必須比 JOB2 的短。具體看下邊的設置。

   另外，在此房間停留，會隨機損失 hp ，至死方休！

   int query_idle( object target ) 返回發呆值 :)

   naihe 23:43 03-10-20
**********************************************************/


#include    "npc_obj/hj_settings/room_amount_hj.h"


#define        JOB1_NEED_IDLE       20
#define        JOB2_NEED_IDLE       31
#define        JOB1_AWARD           800
#define        JOB2_AWARD           80
#define        JOB2_AWARD_SKILLS    2

void full_all( object me );

int me_ok( object me )
{
    if( !me || !environment(me) || environment(me) != this_object()
       || query_temp("huanjing", me) != "start" || query_temp("hj_hp", me)<1 )
        return 0;

    return 1;
}


void create()
{
    set("j1_time", JOB1_NEED_IDLE );
    set("j2_time", JOB2_NEED_IDLE );

    set("room_mark",mark);
    set("short",MAG"幻境"NOR+GRN"·迷失之寶物隱匿之林"NOR);

    set("long", "你剛走過來，卻發現這裡是一小方水潭，水潭之水清幽平靜，潭邊立著一個
小亭(ting)。你只見月色清風，粼光閃爍，端的是舒心暢懷，清雅無比。你似乎
已忘了密林中的兇殺嘶喊，剛才的緊迫就似已離你而去。
                                                           [1;33m●[37;0m

                                            [1;32m.. .[37;0m      [1;34mI[37;0m       [1;32m..[37;0m
                                            [1;32m..[37;0m      [1;34m,'.`.[37;0m
                                              [1;34m.__,-'.:::.`-.__,[37;0m  [1;32m.[37;0m
                                               [1;34m~-------------~[37;0m      ");

    // string to long, 要分開來 set, 5555555
    set("long", query("long") + "
                                                 [1;31m_|=|___|=|_[37;0m
                                           [1;34m.__,-'.:::::::::.`-.__,[37;0m
                               [37m[37;0m             [1;34m~-------------------~[37;0m
                               [37m |[37;0m              [1;31m_|_|_|___|_|_|_[37;0m
                               [37m###################################[37;0m
[42m     [30m▂▃▄▅▆▇▆▅▄▅▆▅▄▃▂▁▂▃▄▅▆▇█▇▆▅▄▃▂▁   [37;0m
        \n");

    // 奈何注：此圖複製自哈工大BBS，顏色設置與其並無二致。亭外岸邊的一豎是我加上的，
    // 為了一些其他的效果。
    // 忘記原作是誰了，在 HJ 毫無商業用途之時，這個圖將保留。
    // 本圖亦是奈何的單機上的 welcome 圖，HOHO。可惜我對畫這個東西
    // 毫無感覺，看這畫的是多美……建議效果：
    // zmud4.62 32bit 漢化版， 宋體，小四（12） 查看，可得最佳效果。
    // naihe 23:25 03-10-20

    set("item_desc",([
        "亭"   : "這是一個小亭子，精緻風雅。亭外岸邊立著一柄權杖(zhang)，十分粗大。\n",
        "小亭" : "這是一個小亭子，精緻風雅。亭外岸邊立著一柄權杖(zhang)，十分粗大。\n",
        "ting" : "這是一個小亭子，精緻風雅。亭外岸邊立著一柄權杖(zhang)，十分粗大。\n",
        "杖"   : "這是一柄權杖，似乎散發著一股詭異的氣息。它上邊刻有一些小字(zi)。\n",
        "權杖" : "這是一柄權杖，似乎散發著一股詭異的氣息。它上邊刻有一些小字(zi)。\n",
        "zhang": "這是一柄權杖，似乎散發著一股詭異的氣息。它上邊刻有一些小字(zi)。\n",
        "字"   : "「幽靈之族權杖 -- 幽靈的武士將由此降臨，暗夜的密林即將展開激戰」\n",
        "小字" : "「幽靈之族權杖 -- 幽靈的武士將由此降臨，暗夜的密林即將展開激戰」\n",
        "zi"   : "「幽靈之族權杖 -- 幽靈的武士將由此降臨，暗夜的密林即將展開激戰」\n",
        ]) );

    set("no_fight", "1");
    set("no_steal", "1");
    set("no_sleep_room", "1");
    set("invalid_startroom",1);

    set("exits",([
        "east" : __DIR__"hj_room2",
        "south" : __DIR__"hj_room11",
        "southeast" : __DIR__"hj_room12",
        ]) );

    setup();
}

void init()
{
    // 所有的共有動作(即 all_room_info_hj.h 及 1_room_info_special.h 共有)
#include "all_common_init.h"

    // 升級功能！！！
    add_action("do_lvup", ({ "levelup", "lvup" }) );
    // npc 進入此地，不管是什麼人，立刻離開
    if( query("hj_game/npc", me) )
        call_out("npc_out", 1, me);
    // 啟動檢測 me 的程序
    if( query_temp("huanjing", me) == "start" )
        call_out("start_check",2,me,query("id", me));
}

// 所有的共有函數(即 all_room_info_hj.h 及 1_room_info_special.h 共有)
#include "all_common_func.h"

void npc_out( object me )
{
    object outroom;
    int or;

    if( !me ) return;
    if( !environment(me) || environment(me) != this_object() )
        return;

    message_vision("$N左右看了一下，急急忙忙地離開了。\n", me);
    if( random(2) ) or = 2;
    else if( random(2) ) or = 11;
    else or = 12;

    outroom = find_object( __DIR__"hj_room"+or );
    if( !outroom ) outroom = load_object( __DIR__"hj_room" + or );
    me->move( outroom );
    message_vision("$N急急忙忙地走了過來。\n", me);
}

void start_check( object me, string id )
{
    if( !me_ok(me) )
    {
        delete("checking_job1_"+ id );
        delete("checking_job2_"+ id );
        delete("checking_lost_hp_"+ id );
        return;
    }

    // 開始執行此人的發呆判斷及扣血程序

    // 並未在執行 checking 此人的 job1 函數，可以進行
    if( !query("checking_job1_"+ id ) )
    {
        set("checking_job1_"+ id, 1);
        call_out( "checking_job1", 5 + random(6), me, id);
    }
    // 同上
    if( !query("checking_job2_"+ id ) )
    {
        if( !query_temp("hj_youling_job", me) )
        {
            set("checking_job2_"+id, 1);
            call_out( "checking_job2", 5 + random(6) , me, id );
        }
    }
    // 同上及上上
    if( !query("checking_lost_hp_"+id) )
    {
        set("checking_lost_hp_"+ id, 1);
        call_out( "lost_hp", 1, me, id );
    }
}

// 在這個地點停留，會不斷地掉HP，直到死為止。
void lost_hp( object me, string id )
{
    if( !me || !me_ok(me) )
    {
        delete("checking_lost_hp_"+ id );
        return;
    }

    // 隨機 lost hp.
    if( random(3) )
    {
        call_out("lost_hp", 5+random(6), me, id );
        return;
    }

    write(HIB"你忽地感到一陣強烈的詭異氣息不知從哪兒散發出來，只覺得心煩氣悶，竟似靈魂正在與自己遠離一般！\n"NOR);
    addn_temp("hj_hp", -(5+random(16)), me);
    call_out("lost_hp", 5+random(6), me, id);
}

// 這是蒐集各族權杖的 JOB。
void checking_job1( object me, string id )
{
    string *job1_ids;
    string msg;
    object *job1_obj_list, temp;
    int i, award_score;

    // 斷線的玩家調用 query_idle() 會出 bug
    if( !me || !me_ok(me) || !interactive(me) )
    {
        delete("checking_job1_"+ id );
        return;
    }
    if( query_idle(me) < JOB1_NEED_IDLE )
    {
        call_out("checking_job1", 5+random(6), me, id);
        return;
    }

    // 發呆時間到
    job1_ids = ({ "manye quanzhang", "mengli quanzhang", "aiyao quanzhang",
            "shanguai quanzhang", "juren quanzhang", });

    job1_obj_list = ({ });

    // 查看其是否有全套權杖
    for( i=0;i<sizeof( job1_ids ); i++ )
    {
        temp = present( job1_ids[i] , me );

        // 發現任何一個不夠，退出檢測程序。
        if( !temp )
        {
            delete("checking_job1_" + id );
            return;
        }
        job1_obj_list += ({ temp });
    }
    // 好的！獲得獎勵。
    message_vision( HIY"$N"HIY"正在凝神細思，忽地自己所帶權杖都發出了耀眼光芒，不約而同地指向幽靈族的權杖！\n"NOR,me);
    msg = HIY + "";
    // 權杖沒有顏色的設置，所以頓號這裡也不用寫顏色了。
    for( i=0; i<sizeof( job1_obj_list ); i++ )
    {
        if( i == 0 )
            msg += job1_obj_list[i] -> name(1);
        else msg += sprintf( "、%s", job1_obj_list[i] -> name(1) );
        destruct( job1_obj_list[i] );
    }

    message_vision( msg +"……\n只見各個權杖接連飛出，猶如飛蛾撲火般撞向幽靈族權杖，竟全部消失不見了！\n$N"HIY"眼看此景，奇異莫名，只驚得說不出話來。\n"NOR, me );

    delete("checking_job1_"+ id );
    award_score = JOB1_AWARD + random( JOB1_AWARD / 10 );
    addn_temp("hj_score", award_score, me);
    tell_object( me, HIR"遊戲提示：你的得分增加了 "+award_score+" 點！\n"NOR );
    return;
}

// 這是去殺幽靈族武士的JOB。
void checking_job2( object me, string id )
{
    object kill_npc, rooms, ling;
    int random_room, yeah = 0;

    // 如果 me 不符合條件，或者 me 已經有 JOB 在身了，結束檢測函數。
    // 這個 JOB 標記是 object 型的，當NPC被別人殺了，JOB會自動結束 :)
    if( !me || !me_ok(me) || query_temp("hj_youling_job", me) || !interactive(me) )
    {
        delete("checking_job2_"+ id );
        return;
    }
    // 這是一個特別判斷。當玩家成功從臣民處得到寶物的重要組合部分時，
    // 將可得到一個“幽靈之令”，有此令在身者，將可以加倍速度得到武士JOB。
    // 此令必須是屬於該玩家的。如玩家身上攜帶過多的令而又發生令牌未執行
    // 自毀程序的情況，則會產生令牌無效的非BUG類錯誤。
    ling = present( "youling ling", me);
    if( ling && query("my_master", ling) == me
         && query("this_time_mark", ling) == query_temp("this_time_mark", me) )
    {
        yeah = 1;
        if( query_idle(me) < JOB2_NEED_IDLE/2 )
        {
            call_out("checking_job2", 5+random(6), me, id);
            return;
        }
    }
    if( !yeah && query_idle(me) < JOB2_NEED_IDLE )
    {
        call_out("checking_job2", 5+random(6), me, id);
        return;
    }

    if( yeah && ling )
        message_vision( HIB"$N"HIB"身上的$n"HIB"忽然發出一陣鬼魅之聲，周圍驟地厲聲四起，似是響起了一片呼應！\n"NOR, me, ling);

    // 成功！發放JOB。
    delete("checking_job2_"+id);
    kill_npc = new( __DIR__"npc_obj/hj_npc_kill" );
    kill_npc->setme( 88 );  // 特殊的 set.

    set("job_master_obj", me, kill_npc);
    set("job_award_score", JOB2_AWARD*9/10+random(JOB2_AWARD/5), kill_npc);
    switch( random(10) )
    {
        // 這個是隨機獎勵 me 的某項技能提升多少級
        case 0..1 :set("job_award_skills", JOB2_AWARD_SKILLS + random(2), kill_npc );
            break;
        // 或者獎勵一點力量，因為力量值很重要，所以不可多獎
        case 8 :set("job_award_power", 1, kill_npc );
            break;
    }
    // 設置一些描述，並且也可以以此為依據，判斷是否自己的NPC，不要白打（很難打！）。
    set("gender",query("gender",  me), kill_npc);
    set("long",query("long",  kill_npc)+"這人看起來竟與"+query("name", me)+"一模一樣！\n", kill_npc);
    set("per",query("per",  me), kill_npc);

    random_room = 2 + random( HJ_ROOM_AMOUNT -1 );
    rooms = find_object( __DIR__"hj_room" + random_room );
    if( !rooms ) rooms = load_object( __DIR__"hj_room" + random_room );
    kill_npc->move( rooms );
    message_vision( BLU"忽地一陣陰風掠起，$N"NOR+BLU"驟然現身，詭異之極。\n"NOR, kill_npc);
    // JOB 獎勵由該 npc 實現。

    set_temp("hj_youling_job", kill_npc, me);
    // 給 me 設置標記，不會繼續發放JOB。
    // 以 object 型來設置JOB，當該NPC死掉(destruct)時，JOB自然結束。

    message_vision( BLU"\n$N"NOR+BLU"正在凝神細思，忽然間只聽得幽靈之族權杖發出一陣梟叫之聲！\n"
        "一個模糊的影子從權杖中激射而出，竟然穿過$N"NOR+BLU"的身體，往外邊急衝而去！\n"
        "$N"NOR+BLU"驚魂未定，似已呆住，恍惚中見得影子似乎是往 "HIR"\""+random_room+"\""NOR+BLU" 去了。\n\n"NOR, me);
    me->start_busy(3);
    // ok,finish.
}

// 非常難的升級制度
// naihe 05-9-3 18:18 按：好象又不是很難。我5天衝到 lv6, lv6 是什麼概念？……很強悍了
// 提高升級難度。
int do_lvup(string arg)
{
    object me = this_player(), rooms;
    int next_lv, score_need, power_need, f_sks_need, y_sks_need, l_sks_need, d_sks_need, heal_sks_need, dh_sks_need, fh_sks_need, gs_sks_need;
    string msg;

    int t;

    if( !me_ok(me) ) return 0;

    if( me->is_busy() || query_temp("hj_need_waiting", me) )
        return notify_fail("你還忙著呢，那麼重要的事情還是等有空的時候再說吧。\n");

    next_lv=query("huanjing2003/lv", me)+1;
    if( next_lv > 9 ) return notify_fail("你現在已經是最高的等級了！\n");

    rooms = find_object( __DIR__"room_door_hj" );
    if( !rooms ) rooms = load_object( __DIR__"room_door_hj" );
    if( !rooms ) return notify_fail("現在誰都不能升級。\n");

    switch( next_lv )
    {
// ######################################################
// 此時，無任何自動保持，所以容易升

        case 1: msg = "1001點得分"; score_need = 1001;
            break;


// ######################################################
// 此時，sks 已可自動保持 5 lv
// 早期的 power 很容易升上去，所以 power 起點定為21點。

        case 2: msg = "1001點得分，風、雨、雷、電技能各31級，21點力量";
                score_need = 1001; t = 31; power_need = 21;

                f_sks_need=t;y_sks_need=t;l_sks_need=t;d_sks_need=t;
            break;


// ######################################################
// 此時，sks 已可自動保持 10 lv

        case 3: msg = "1001點得分，風、雨、雷、電技能各41級，26點力量";
                score_need = 1001; t = 41; power_need = 26;

                f_sks_need=t;y_sks_need=t;l_sks_need=t;d_sks_need=t;
            break;


// ######################################################
// 此時，sks 已可自動保持 15 lv
// 這是一個關鍵點，升了本級後，sks lv 可保持 20，即可以
// 使用 yun 特殊技。所以，要求高些

        case 4: msg = "999 點得分，風、雨、雷、電、恢復、奪魂、飛火、"
                        "滾石技能各41級，31點力量";
                score_need = 999; t = 41; power_need = 31;

                f_sks_need=t;y_sks_need=t;l_sks_need=t;d_sks_need=t;
                heal_sks_need=t;dh_sks_need=t;fh_sks_need=t;gs_sks_need=t;
            break;


// ######################################################
// 此時，sks 已可自動保持 20 lv

        case 5: msg = "1001點得分，風、雨、雷、電、恢復、奪魂、飛火、"
                        "滾石技能各51級，31點力量";
                score_need = 1001; t = 51; power_need = 31;

                f_sks_need=t;y_sks_need=t;l_sks_need=t;d_sks_need=t;
                heal_sks_need=t;dh_sks_need=t;fh_sks_need=t;gs_sks_need=t;
            break;


// ######################################################
// 此時，sks 已可自動保持 25 lv
// 這個升級條件和 lv 5 一樣，但是相對容易些了

        case 6: msg = "1001點得分，風、雨、雷、電、恢復、奪魂、飛火、"
                        "滾石技能各51級，31點力量";
                score_need = 1001; t = 51; power_need = 31;

                f_sks_need=t;y_sks_need=t;l_sks_need=t;d_sks_need=t;
                heal_sks_need=t;dh_sks_need=t;fh_sks_need=t;gs_sks_need=t;
            break;


// ######################################################
// 此時，sks 已可自動保持 30 lv

        case 7: msg = "1001點得分，風、雨、雷、電、恢復、奪魂、飛火、"
                        "滾石技能各61級，36點力量";
                score_need = 1001; t = 61; power_need = 36;

                f_sks_need=t;y_sks_need=t;l_sks_need=t;d_sks_need=t;
                heal_sks_need=t;dh_sks_need=t;fh_sks_need=t;gs_sks_need=t;
            break;


// ######################################################
// 此時，sks 已可自動保持 35 lv
// 這又是一個關鍵點，up lv 後，將可保持 sks 40, 即可以 pfm.
// 特別難！
        case 8:msg = "88點得分，風、雨、雷、電、恢復、奪魂、飛火、"
                        "滾石技能各88級，41點力量";
                score_need = 88; t = 88; power_need = 41;

                f_sks_need=t;y_sks_need=t;l_sks_need=t;d_sks_need=t;
                heal_sks_need=t;dh_sks_need=t;fh_sks_need=t;gs_sks_need=t;
            break;


// ######################################################
// 此時，sks 已可自動保持 40 lv
// 這是最後的一級，如果有人配合，那倒不算挺難 :)
// 因為力量的要求降低了
// sks 的要求很容易達到的，hoho

        case 9:msg = "1888點得分，風、雨、雷、電、恢復、奪魂、飛火、"
                        "滾石技能各66級，31點力量，\n"
                "並且在升級後，你所有的技能、力量都將被清除！";
                score_need = 1888; t = 66; power_need = 31;

                f_sks_need=t;y_sks_need=t;l_sks_need=t;d_sks_need=t;
                heal_sks_need=t;dh_sks_need=t;fh_sks_need=t;gs_sks_need=t;
            break;
    }

// ######################################################
// ######################################################
// ######################################################


    write( "你將升到第 "+next_lv+" 級，需要 "+msg+" 。\n");
    if( !arg || arg != "now")
        return notify_fail("如確實想升級，請輸入 <levelup now> 。升級後，將會對應所需條件對你的各項能力進行削減。\n");

// 開始升級

    if( score_need && query_temp("hj_score", me)<score_need )
        return notify_fail("你沒有足夠的得分。\n");

    if( power_need && query_temp("hj_game_mepower", me)<power_need )
        return notify_fail("你沒有足夠的力量。\n");

    if( f_sks_need && (!query_temp("hj_game_skills/hfzj", me )
               || query_temp("hj_game_damages/hfzj", me)<f_sks_need) )
        return notify_fail("你的「呼風之技」等級不夠。\n");

    if( y_sks_need && (!query_temp("hj_game_skills/hyzj", me )
               || query_temp("hj_game_damages/hyzj", me)<y_sks_need) )
        return notify_fail("你的「喚雨之技」等級不夠。\n");

    if( l_sks_need && (!query_temp("hj_game_skills/llzj", me )
               || query_temp("hj_game_damages/llzj", me)<l_sks_need) )
        return notify_fail("你的「落雷之技」等級不夠。\n");

    if( d_sks_need && (!query_temp("hj_game_skills/ydzj", me )
               || query_temp("hj_game_damages/ydzj", me)<d_sks_need) )
        return notify_fail("你的「引電之技」等級不夠。\n");

    if( heal_sks_need && (!query_temp("hj_game_skills/heal", me )
               || query_temp("hj_game_damages/heal", me)<heal_sks_need) )
        return notify_fail("你的「恢復之技」等級不夠。\n");

    if( dh_sks_need && (!query_temp("hj_game_skills/dhzj", me )
               || query_temp("hj_game_damages/dhzj", me)<dh_sks_need) )
        return notify_fail("你的「奪魂之技」等級不夠。\n");

    if( fh_sks_need && (!query_temp("hj_game_skills/fhzj", me )
               || query_temp("hj_game_damages/fhzj", me)<fh_sks_need) )
        return notify_fail("你的「飛火之技」等級不夠。\n");

    if( gs_sks_need && (!query_temp("hj_game_skills/gszj", me )
               || query_temp("hj_game_damages/gszj", me)<gs_sks_need) )
        return notify_fail("你的「滾石之技」等級不夠。\n");

// all ok now!

    set("huanjing2003/lv", next_lv, me);
    if( score_need)addn_temp("hj_score", -(score_need-1), me);
    if( power_need)addn_temp("hj_game_mepower", -(power_need-1), me);
    if( f_sks_need)addn_temp("hj_game_damages/hfzj", -(f_sks_need-1), me);
    if( y_sks_need)addn_temp("hj_game_damages/hyzj", -(y_sks_need-1), me);
    if( l_sks_need)addn_temp("hj_game_damages/llzj", -(l_sks_need-1), me);
    if( d_sks_need)addn_temp("hj_game_damages/ydzj", -(d_sks_need-1), me);
    if( heal_sks_need)addn_temp("hj_game_damages/heal", -(heal_sks_need-1), me);
    if( dh_sks_need)addn_temp("hj_game_damages/dhzj", -(dh_sks_need-1), me);
    if( fh_sks_need)addn_temp("hj_game_damages/fhzj", -(fh_sks_need-1), me);
    if( gs_sks_need)addn_temp("hj_game_damages/gszj", -(gs_sks_need-1), me);

    if( query_temp("hj_game_mepower", me)<5 )
        set_temp("hj_game_mepower", 5, me);
    set("huanjing2003/last_power",query_temp("hj_game_mepower",  me), me);
    set("huanjing2003/last_skills_lv",query_temp("hj_game_damages",  me), me);

// 9級將清除所有累積，但累積次數還有效
    if( next_lv == 9 )
    {
        delete("huanjing2003/last_power", me);
        delete("huanjing2003/last_skills_name", me);
        delete("huanjing2003/last_skills_lv", me);
        delete("huanjing2003/last_hp_max", me);
        delete_temp("hj_game_skills", me);
        delete_temp("hj_game_damages", me);
        set_temp("hj_game_mepower", 10, me);
        set_temp("hj_hp_max", 700, me);
        set_temp("hj_game_skills/heal", "恢復之技", me);
        set_temp("hj_game_damages/heal", 3+random(8), me);
    }

    me->save();
    me->start_busy(5);

    message_vision( HIW"\n\n$N"HIW"大喝一聲，唸咒文道：“浮雲清風，盡納我懷，幽靈再現，予我力量！”\n\n"
        "只見$N"HIW"全身銀光閃耀，能力修為明顯地上了一個層次！\n\n\n"NOR, me);

    rooms->save_player_level(query("name", me),query("id", me),query("huanjing2003/lv", me),time());
    return 1;
}
