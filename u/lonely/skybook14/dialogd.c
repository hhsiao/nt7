
/***************************************************
dialogd.c
***************************************************/
#include <ansi.h>

inherit F_DBASE;

// 指定時間是否為週末
public int is_weekend_at(int t)
{       
        string str_ctime;


        // 判斷指定時間是否為週末
        if (t > 0)
        {
                if (sscanf(ctime(t), "Sat %s", str_ctime) || sscanf(ctime(t), "Sun %s", str_ctime))
                        return 1;               
                else
                        return 0;
        }
        
        return 0;
}

int weekend()
{
        string str_ctime;
                
        // 當前時間是否為週末
        if (sscanf(ctime(time()), "Sat %s", str_ctime) || sscanf(ctime(time()), "Sun %s", str_ctime))
                return 1;

        return 0;               
}

// 當前時間是否為週末
public int is_weekend()
{
        

        // 週五晚20:00開始到週日晚23：59為週末
        if (weekend() || 
            is_weekend_at(time() + 4 * 3600))   // 週五20：00後
            return 1;
            
        return 0;
        
}

// 指定時間是周幾
/*
Mon  - 1
Tue  - 2
Wed  - 3
Thu  - 4
Fri  - 5
Sat  - 6
Sun  - 7
*/
public int weeknum(int t)
{
        string stmp, swk;
        
        mapping wk = ([
                "Mon" : 1,
                "Tue" : 2,
                "Wed" : 3,
                "Thu" : 4,
                "Fri" : 5,
                "Sat" : 6,
                "Sun" : 7,
        ]);
        
        if (sscanf(ctime(t), "%s %s", swk, stmp) == 2)
                return wk[swk];

        return 0;
}

void create() 
{
        seteuid(ROOT_UID);
        set("channel_id", "對話精靈");
        set("name", HIW "對話精靈" HIM);

        // 定時播報繽紛週末信息
        remove_call_out("broad_weekendinfo");
        call_out("broad_weekendinfo", 3600);
}

// 播報繽紛週末信息
void broad_weekendinfo()
{
        remove_call_out("broad_weekendinfo");
        call_out("broad_weekendinfo", 3600);
        
        if (is_weekend())
        {
                message_system(HIY "炎黃" HIG "繽" HIM "紛" HIC "周" HIM "末" HIY
                               "火熱進行中，詳情請輸入 " HIR "wkgift info" HIY " 查看。 \n" NOR);
        }       

        return;
}

// 模擬對話模式輸出信息：僅給玩家1個人看到，且與說話NPC必須在同一房間
public void start_dialog(object npc, object me, string *msg, int index, int flag)
{

        if (! objectp(npc) || ! objectp(me))return;
        
        if (index == 0)
        {
                if (me->query_temp("is_in_dialog"))
                {
                        tell_object(me, HIR "你正在進行情景對話或故事，請稍後再試或退出(exit)遊戲後重新登錄！\n" NOR);
                        return;
                }
                else
                {
                        me->set_temp("is_in_dialog", 1);
                }
        }
        
        if (environment(npc) != environment(me))
        {
                me->delete_temp("is_in_dialog");
                return;
        }
        
        // 對話結束，進行回調
        if (index >= sizeof(msg))
        {
                me->delete_temp("is_in_dialog");
                npc->dialog_end(me, flag);
                return;
        }
        
        if (index % 2 == 1)             
                tell_object(me, HIY + "=" + msg[index] + "\n" NOR);
        else
                tell_object(me, HIM + "=" + msg[index] + "\n" NOR);     

        index += 1;

        call_out("start_dialog", 6, npc, me, msg, index, flag);

        return;
}

// 模擬對話模式輸出信息：周圍房間內所有人看到，且與說話NPC必須在同一房間
public void start_dialog2(object npc, object me, string *msg, int index, int flag)
{

        if (! objectp(npc) || ! objectp(me))return;
        
        if (index == 0)
        {
                if (me->query_temp("is_in_dialog"))
                {
                        tell_object(me, HIR "你正在進行情景對話或故事，請稍後再試或退出(exit)遊戲後重新登錄！\n" NOR);
                        return;
                }
                else
                {
                        me->set_temp("is_in_dialog", 1);
                }
        }

        if (environment(npc) != environment(me))
        {
                me->delete_temp("is_in_dialog");
                return;
        }


        // 對話結束，進行回調
        if (index >= sizeof(msg))
        {
                me->delete_temp("is_in_dialog");
                npc->dialog_end(me, flag);              
                return;
        }
        
        if (index % 2 == 1)             
                message_vision(HIY + "=" + msg[index] + "\n" NOR, npc, me);
        else
                message_vision(HIM + "=" + msg[index] + "\n" NOR, npc, me);

        index += 1;

        call_out("start_dialog2", 6, npc, me, msg, index, flag);

        return;
}

// 模擬對話模式輸出信息：周圍房間所有人看到，只要玩家在線無論什麼地方都可以看到對話輸出
public void start_dialog3(object npc, object me, string *msg, int index, int flag)
{

        if (! objectp(npc) || ! objectp(me))return;
        
        // if (environment(npc) != environment(me))return;
        
        if (index == 0)
        {
                if (me->query_temp("is_in_dialog"))
                {
                        tell_object(me, HIR "你正在進行情景對話或故事，請稍後再試或退出(exit)遊戲後重新登錄！\n" NOR);
                        return;
                }
                else
                {
                        me->set_temp("is_in_dialog", 1);
                }
        }
                
        // 對話結束，進行回調
        if (index >= sizeof(msg))
        {
                me->delete_temp("is_in_dialog");
                npc->dialog_end(me, flag);
                return;
        }
        
        if (index % 2 == 1)             
                message_vision(HIM + "=" + msg[index] + "\n" NOR, npc, me);
        else
                message_vision(HIM + "=" + msg[index] + "\n" NOR, npc, me);

        index += 1;

        call_out("start_dialog3", 6, npc, me, msg, index, flag);

        return;
}


// 模擬對話模式輸出信息：只有玩家一人看到，只要玩家在線無論什麼地方都可以看到對話輸出
public void start_dialog4(object npc, object me, string *msg, int index, int flag)
{

        if (! objectp(npc) || ! objectp(me))return;
        
        // if (environment(npc) != environment(me))return;
        
        if (index == 0)
        {
                if (me->query_temp("is_in_dialog"))
                {
                        tell_object(me, HIR "你正在進行情景對話或故事，請稍後再試或退出(exit)遊戲後重新登錄！\n" NOR);
                        return;
                }
                else
                {
                        me->set_temp("is_in_dialog", 1);
                }
        }
                
        // 對話結束，進行回調
        if (index >= sizeof(msg))
        {
                me->delete_temp("is_in_dialog");
                npc->dialog_end(me, flag);              
                return;
        }

        if (index % 2 == 1)             
                tell_object(me, HIY + "=" + msg[index] + "\n" NOR, npc);
        else
                tell_object(me, HIM + "=" + msg[index] + "\n" NOR, npc);

        index += 1;

        call_out("start_dialog4", 6, npc, me, msg, index, flag);

        return;
}
