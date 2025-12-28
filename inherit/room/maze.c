// This program is a part of NITAN MudLIB

#include <maze.h>
#include <ansi.h>

inherit ROOM;

void destruct_me();

void create()
{
    set("short", "迷宮");
    set("long", @LONG
這是一間寬敞的石屋，四周巨石壘就的牆壁泛出幽幽的青色光芒，兩盞青銅
燈吐出一尺高的火焰，飄忽閃爍，偶然有燈花爆裂的輕響，更令人感到窒息般的
寂靜。地上是丈許見方的青石板鋪就，房間中央一塊白色石板格外醒目，上面雕
刻著細密的圖紋，讓人不由自主的想上前查看（mazemap）一番。
LONG );
    set("no_clean_up", 1);
    set("no_drop", 1);
    set("no_sleep_room", 1);
    set("born_time", time() );
    
    setup();
}

void init()
{
    object me, room, next_room;
    int xianjing;
    string mazename;
    int damage;
    
    add_action("do_chakan", "mazemap");

    // 添加陷阱程序
    me = this_player();
    room = this_object();
    
    if ( !me ) return;
    
    xianjing=query("maze/xianjing", room);
    if ( !xianjing ) return;
    
    mazename=query("maze/mazename", room);
    if ( !stringp(mazename) ) return;
    
    switch (xianjing)
    {
        case BUSY:
            message_vision(HIR "\n$N腳下一滑，差點摔個嘴啃泥，好不容易穩住身子，才感覺腳踝扭傷了，好痛啊...\n\n" NOR, me);
            me->start_busy(5);
            break;
        case TRIP:
            message_vision(HIR "\n$N一腳踩上了什麼東西，身形再也把持不住，猛的向前滑出，只留下一聲驚叫久久迴盪...\n\n" NOR, me);
            next_room = MAZE_D->trip_maze(mazename, room);
            if ( objectp(next_room) )
            {
                me->move(next_room);
            }
            break;
        case LOSTMAP:
            message_vision(HIR "\n$N只聽得腳下一聲喀嚓輕響，忽見到房間中央的白色石板閃起一道強光，旋即迅速黯淡下去...\n\n" NOR, me);
            MAZE_D->lostmap_maze(mazename);
            break;
        case CHANGEMAP:
            MAZE_D->init_maze(mazename);            
            message_vision(HIR "\n$N一腳踩到了什麼東西，急惶惶的把腳收起，卻已經聽到陣陣沉悶的聲音從地下響起...\n" NOR
                + HIR "只見四周光影晃動，整個房間似乎在快速移動，等一切安靜下來，周遭景象似乎有所改變。\n\n" NOR, me);
            break;
        case WOUND:
            message_vision(HIR "\n只聽得一聲機括脆響，$N下意識的趕緊避讓，卻為時已晚，一支鋼弩不偏不倚正好射中$N。\n" NOR
                + HIR "$N驚怒交加，傷口處痛徹心扉，終於忍不住連聲哀叫起來。\n\n" NOR, me);
            damage=query("max_qi", me);
            damage = damage/10 + random(damage/10) + 1;
            me->receive_wound("qi", damage);
            break;
        default:
            break;
    }
    
    // 把這個房間的陷阱去除
    delete("maze/xianjing", room);
    MAZE_D->remove_xianjing(mazename, room);
    
    return;    
}

int clean_up()
{
    if (time() - query("born_time") > MAZE_LIFT_CYCLE)
    {
        destruct_me();
        return 0;
    }
    
    return 1;
}

void destruct_me()
{
    object *obs;
    int i, user_num;

    obs = filter_array(all_inventory(), (: userp($1) || playerp($1) :));
    user_num = sizeof(obs);
    if (user_num)
    {
                message("vision", HIW "\n你突然覺得周圍的一切都晃動起來，逐漸化為虛無...\n\n" NOR, this_object());
        for (i = 0; i < user_num; i ++)
        {
            obs[i]->move(ROOM_EXIT_FILE);
            message("vision", "地面忽然打開一個暗道，只見" + obs[i]->name() + "鑽了出來。\n", 
                    environment(obs[i]), ({ obs[i] }));
        }
    }

    destruct(this_object());
    return;
}

int do_chakan(string arg)
{
    object me, room;
    string map = "";
    string mazename;
    
    
    me = this_player();
    if (!me) return 0;
    
    room = this_object();
    mazename=query("maze/mazename", room);
    
    if (!stringp(mazename))
    {
        map = "你仔細的查看石板，但是模模糊糊的什麼都看不清...\n";
    }
    else
    {
        if (wizardp(me) && !stringp(arg) )
            map = MAZE_D->get_deep_map(mazename, room);
        else
            map = MAZE_D->get_comm_map(mazename, room);
    }

    if (!stringp(map))
    {
        map = "你仔細的查看石板，但是模模糊糊的什麼都看不清...\n";
    }

    me->start_more(map);
    
    return 1;
}

int valid_leave(object me, string dir)
{
    if( dir == "out" && userp(me) && query("exits/out", this_object()) )
    {
        MAZE_D->check_maze(query("maze/mazename", this_object()));
    }

    return ::valid_leave(me, dir);
}
