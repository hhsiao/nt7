// 副本系統控制文件
#define MEMBER_D          "/adm/daemons/memberd"

#include <ansi.h>

void move_all_invalid_user(object me); //移出
int move_next_fb_room(object me, object ob_room, string into_msg, string into_msg_team, string fb_name, object last_room);

// 副本重置時間
mapping fb_reset_time = ([
        "天機"              : 6 * 3600,
        "布達拉宮寶藏"      : 6 * 3600,
        
]);

// 移動到指定副本 將當前PLAYER或PLAYER為首的隊伍移動到新的副本場景
// me, 新副本OB，單人進入提示，組隊進入提示
// 參數nWhere = 1代表從存檔點進入 為0代表在副本中移動
// nWhere_save_point 代表存檔點 如 /fuben/天機/save/冰火島西岸
int move_new_fb(object me, object ob_room, string into_msg, string into_msg_team, string fb_name, int nWhere, string nWhere_save_point)
{
        object *t;
        object ob;
        object ob_shensheng, ob_huoyan;
        
        if (! objectp(me))return 0;
        if (! objectp(ob_room))return 0;        
        
        t = me->query_team();

        if (! MEMBER_D->is_valib_member(me->query("id")))
        {
                tell_object(me, "你還是非會員，無法進入副本！\n");
                return 1;
        }
        if (! me->query("scborn/ok"))
        {
                tell_object(me, "你還未轉世，無法進入副本！\n");
                return 1;                       
        }
        
        if (me->query("combat_exp") < 10000000)
        {
                tell_object(me, "你實戰經驗不足，無法進入副本！\n");
                return 1;                               
        }

        // 未開啟該副本則不能參與
        if (! me->query("fuben/" + fb_name + "/open"))
        {
                tell_object(me, "你還未開啟" + fb_name + "副本，無法進入！\n");
                return 1;
        }

        // 代表在副本中移動
        if (! nWhere)
        {
                return move_next_fb_room(me, ob_room, into_msg, into_msg_team, fb_name, 0);
        }
        
        // 檢查該玩家或組隊玩家身上是否有其他玩家，有則任何人均不可進入
        if (! arrayp(t))
        {
        }
        t -= ({ 0 });
        if (! me->is_team_leader() || sizeof(t) < 1)
        {
        }
        else
        {
        }
        
        // 如果是從存檔點進入，開啟副本後再次從頭進入也算是從存檔點進入
        if (nWhere == 1)
        {
                // 沒有該存檔點則無法進入
                if (! me->query(nWhere_save_point))
                {
                        tell_object(me, "你沒有該存檔點，無法進入！\n");
                        return 1;
                }
        }
        
        // 查詢上次進入副本的重置時間
        if (time() - me->query("fuben/" + fb_name + "/last_join_time")  < fb_reset_time[fb_name])
        {
                tell_object(me, "你距離上次進入" + fb_name + "副本的時限不夠，無法進入， 指令 fb list 可查看詳細情況。\n");
                return 1;
        }

        // 身上火焰之晶不足，則無法進入
        if (! me->query("fuben/" + fb_name + "/first_open"))
        {
                if (! objectp(ob_huoyan = present("huoyan zhijing", me)))
                {
                        tell_object(me, "你身上沒有火焰之晶，無法從存檔點或重新進入副本。\n");
                        return 1;
                }
        }
        else // 開啟副本成功後，首次進入不扣除火焰之晶
        {
                
        }
                
        if (! arrayp(t))
        {               
                // 身上火焰之晶不足，則無法進入
                if (! me->query("fuben/" + fb_name + "/first_open"))
                {
                        if (! objectp(ob_huoyan = present("huoyan zhijing", me)))
                        {
                                tell_object(me, "你身上沒有火焰之晶，無法從存檔點或重新進入副本。\n");
                                return 1;
                        }
                        destruct(ob_huoyan);
                }
                else // 開啟副本成功後，首次進入不扣除火焰之晶
                {
                        me->set("fuben/" + fb_name + "/first_open", 0);
                }
                                
                tell_object(me, HIG "\n" + into_msg + "\n\n" NOR);
                
                me->move(ob_room);
                // 設置進入副本時間
                me->set("fuben/" + fb_name + "/last_join_time", time());
                me->save();
                return 1;
        }

        t -= ({ 0 });
        if (! me->is_team_leader() || sizeof(t) < 1)
        {
                // 身上火焰之晶不足，則無法進入
                if (! me->query("fuben/" + fb_name + "/first_open"))
                {
                        if (! objectp(ob_huoyan = present("huoyan zhijing", me)))
                        {
                                tell_object(me, "你身上沒有火焰之晶，無法從存檔點或重新進入副本。\n");
                                return 1;
                        }
                        destruct(ob_huoyan);
                }
                else // 開啟副本成功後，首次進入不扣除火焰之晶
                {
                        me->set("fuben/" + fb_name + "/first_open", 0);
                }               

                tell_object(me, HIG "\n" + into_msg + "\n\n" NOR);
                
                me->move(ob_room);
                // 設置進入副本時間
                me->set("fuben/" + fb_name + "/last_join_time", time());
                me->save();
                return 1;               
        }

        foreach ( ob in t)
        {
                if (! MEMBER_D->is_valib_member(ob->query("id")))
                {
                        tell_object(ob, "非會員，無法進入副本！\n");
                        continue;
                }
                if (! ob->query("scborn/ok"))
                {
                        tell_object(ob, "你還未轉世，無法進入副本！\n");
                        continue;
                }
                if (ob->query("combat_exp") < 10000000)
                {
                        tell_object(ob, "你實戰經驗不足，無法進入副本！\n");    
                        continue;                       
                }
                // 未開啟該副本則不能參與
                if (! ob->query("fuben/" + fb_name + "/open"))
                {
                        tell_object(ob, "你還未開啟" + fb_name + "副本，無法進入！\n");
                        return 1;
                }

                // 如果已經開啟了該副本，從頭進入則算作從存檔點進入
                if (! nWhere)
                {
                        if (ob->query("fuben/" + fb_name + "/open"))
                        {
                                nWhere = 1;
                                nWhere_save_point = "/fuben/" + fb_name + "/save/重新開始";
                        }
                }
                // 如果是從存檔點進入
                if (nWhere == 1)
                {
                        // 沒有該存檔點則無法進入
                        if (! ob->query(nWhere_save_point))
                        {
                                tell_object(ob, "你沒有該存檔點，無法進入！\n");
                                continue;
                        }
                }       
                
                // 查詢上次進入副本的重置時間
                if (time() - ob->query("fuben/" + fb_name + "/last_join_time")  < fb_reset_time[fb_name])
                {
                        tell_object(ob, "你距離上次進入" + fb_name + "副本的時限不夠，無法進入， 指令 fb list 可查看詳細情況。\n");
                        continue;
                }

                // 身上火焰之晶不足，則無法進入
                if (! ob->query("fuben/" + fb_name + "/first_open"))
                {
                        if (! objectp(ob_huoyan = present("huoyan zhijing", ob)))
                        {
                                tell_object(ob, "你身上沒有火焰之晶，無法從存檔點或重新進入副本。\n");
                                continue;
                        }
                        destruct(ob_huoyan);
                }
                else // 開啟副本成功後，首次進入不扣除火焰之晶
                {
                        ob->set("fuben/" + fb_name + "/first_open", 0);                 
                }

                tell_object(ob, HIG "\n組隊：" + into_msg_team + "\n\n" NOR);
                
                ob->move(ob_room);
                // 設置進入副本時間
                ob->set("fuben/" + fb_name + "/last_join_time", time());
                ob->save();
        }
        return 1;
}
// 副本中移動，用於將指定隊長及所有隊伍成員一起移動到下一房間
int move_next_fb_room(object me, object ob_room, string into_msg, string into_msg_team, string fb_name, object last_room)
{
        object *t;
        object ob;
        
        if (! objectp(me))return 0;
        if (! objectp(ob_room))return 0;        
        
        t = me->query_team();

        if (! arrayp(t))
        {
                tell_object(me, HIG "\n" + into_msg + "\n\n" NOR);

                me->move(ob_room);
                
                if (objectp(last_room))destruct(last_room);
                
                return 1;
        }

        t -= ({ 0 });
        if (! me->is_team_leader() || sizeof(t) < 1)
        {

                tell_object(me, HIG "\n" + into_msg + "\n\n" NOR);
                
                me->move(ob_room);

                if (objectp(last_room))destruct(last_room);
                
                return 1;               
        }

        foreach ( ob in t)
        {

                tell_object(ob, HIG "\n組隊：" + into_msg_team + "\n\n" NOR);
                
                ob->move(ob_room);

        }
        
        if (objectp(last_room))destruct(last_room);
        return 1;
}

// 挑戰BOSS -- HELP BOSS，用於將指定隊長及所有隊伍成員一起移動到下一房間
// time_limit 時間限制，表示該BOSS副本限制time_limit內只能挑戰一次
int move_boss_fb_room(object me, object ob_room, string into_msg, string into_msg_team, string fb_name, object last_room, int time_limit, int cost)
{
        object *t;
        object ob;
        
        if (! objectp(me))return 0;
        if (! objectp(ob_room))return 0;        
        
        t = me->query_team();

        if (! arrayp(t))
        {
                if (time() - me->query(fb_name + "/last_time") < time_limit)
                {
                        tell_object(me, HIG "\n你還需要再等待" + sprintf("%d", time_limit + me->query(fb_name + "/last_time") -time()) + 
                                              "秒後才能再次進入該空間！\n" NOR);
                        return 1;
                }
                
                if (me->query("stocks/balance") < cost)
                {
                        tell_object(me, HIG "\n你無法支付進入空間的費用，將被阻止進入空間。\n" NOR);
                        return 1;
                }
                else
                {
                        me->add("stocks/balance", -1 * cost);
                        me->save();
                }
                
                tell_object(me, HIG "\n" + into_msg + "\n\n" NOR);

                move_all_invalid_user(me);
                
                me->move(ob_room);
                me->set(fb_name + "/last_time", time());

                if (ob_room->query("id") == "huashan zhidian")
                        MYGIFT_D->check_mygift(me, "newbie_mygift/joinfuben");
                
                me->save();
                if (objectp(last_room))destruct(last_room);
                
                return 1;
        }

        t -= ({ 0 });
        if (! me->is_team_leader() || sizeof(t) < 1)
        {

                if (time() - me->query(fb_name + "/last_time") < time_limit)
                {
                        tell_object(me, HIG "\n你還需要再等待" + sprintf("%d", time_limit + me->query(fb_name + "/last_time") -time()) + 
                                              "秒後才能再次進入該空間！\n" NOR);
                        return 1;
                }
                
                if (me->query("stocks/balance") < cost)
                {
                        tell_object(me, HIG "\n你無法支付進入空間的費用，將被阻止進入空間。\n" NOR);
                        return 1;
                }
                else
                {
                        me->add("stocks/balance", -1 * cost);
                        me->save();
                }
                                
                tell_object(me, HIG "\n" + into_msg + "\n\n" NOR);
                
                move_all_invalid_user(me);
                
                me->move(ob_room);
                me->set(fb_name + "/last_time", time());
                
                if (ob_room->query("id") == "huashan zhidian")
                        MYGIFT_D->check_mygift(me, "newbie_mygift/joinfuben");
                
                
                me->save();
                if (objectp(last_room))destruct(last_room);
                
                return 1;               
        }

        // 首先判斷隊長是否可以進入，如果隊長不能進入則整個隊伍不能進入

        if (time() - me->query(fb_name + "/last_time") < time_limit)
        {
                tell_object(me, HIG "\n你還需要再等待" + sprintf("%d", time_limit + me->query(fb_name + "/last_time") -time()) + 
                                      "秒後才能再次進入該空間！\n" NOR);
                return 1;
        }
        if (me->query("stocks/balance") < cost)
        {
                tell_object(me, HIG "\n你無法支付進入空間的費用，將被阻止進入空間。\n" NOR);
                return 1;
        }

        foreach ( ob in t)
        {
                // 非隊長重新計算time_limit
                if (! ob->is_team_leader())
                {
                        object obj;
                        mapping boss_list;
                        string *keys_boss_list;
                        int new_time_limit;
                        
                        if (! objectp(obj = find_object("/kungfu/class/misc/fuben/boss/jieyinshi")))
                                obj = load_object("/kungfu/class/misc/fuben/boss/jieyinshi");
                        
                        boss_list = obj->show_time_delay(1);
                        keys_boss_list = explode(boss_list[fb_name], ":");
                        sscanf(keys_boss_list[3], "%d", new_time_limit);
                        time_limit = new_time_limit * 3600;
                        
                        // vip縮短冷卻時間
                        switch(ob->GetVipLevel())
                        {
                        case 1:
                                time_limit = time_limit - time_limit / 10;
                        break;
                        case 2:
                                time_limit = time_limit - time_limit * 2 / 10;
                        break;
                        case 3:
                                time_limit = time_limit - time_limit * 3 / 10;  
                        break;
                        case 4:
                                time_limit = time_limit - time_limit * 4 / 10;  
                        break;
                        case 5:
                                time_limit = time_limit - time_limit * 5 / 10;  
                        break;
                        case 6:
                                time_limit = time_limit - time_limit * 6 / 10;  
                        break;                                  
                        }
                        // 酷爽夏日活動
                        if (MEMBER_D->ifdatein("2013-5-25", "2013-6-20") == 1)
                        {
                                time_limit /= 2;
                        }
                        
                }

                if (time() - ob->query(fb_name + "/last_time") < time_limit)
                {
                        tell_object(ob, HIG "\n你還需要再等待" + sprintf("%d", time_limit + ob->query(fb_name + "/last_time") -time()) + 
                                              "秒後才能再次進入該空間！\n" NOR);
                        continue;
                }
                
                if (ob->query("stocks/balance") < cost)
                {
                        tell_object(ob, HIG "\n你無法支付進入空間的費用，將被阻止進入空間。\n" NOR);
                        continue;
                }
                else
                {
                        ob->add("stocks/balance", -1 * cost);
                        ob->save();
                }

                tell_object(ob, HIG "\n組隊：" + into_msg_team + "\n\n" NOR);
                
                move_all_invalid_user(ob);
                
                ob->move(ob_room);
                ob->set(fb_name + "/last_time", time());
                
                if (ob_room->query("id") == "huashan zhidian")
                        MYGIFT_D->check_mygift(ob, "newbie_mygift/joinfuben");
                
                ob->save();
        }
        
        if (objectp(last_room))destruct(last_room);
        return 1;
}

void move_all_invalid_user(object me)
{
        int i;
        object *inv;

                        
        // 把背起的用戶放下來
        inv = deep_inventory(me);
        for (i = 0; i < sizeof(inv); i++)
        {
                if (! playerp(inv[i])) continue;

                // 被人揹起的用戶
                inv[i]->move(environment(me));                
        }
        
}

// 單人副本，只移動當前player,身上，背上，和組隊中的player均不移動
int move_lonely_fb_room(object me, object ob_room, string into_msg, string into_msg_team, string fb_name)
{
        object ob;
        
        if (! objectp(me))return 0;
        if (! objectp(ob_room))return 0;        
        
        tell_object(me, HIG "\n" + into_msg + "\n\n" NOR);

        // 移除所有非法連帶用戶
        move_all_invalid_user(me);

        me->move(ob_room);
        me->save();
        
        return 1;


        return 1;
}
