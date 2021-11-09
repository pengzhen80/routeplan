//
// Created by design27 on 2021/5/3.
//

#include<functional>
#include<memory>
#include<vector>
#include<string>

#ifndef CORE_CORE_CONNECT_H
#define CORE_CORE_CONNECT_H

namespace Core_Connect
{



#define emit
#define slots
#define signals public
#define event_connect(sender,signal,slot) ((sender)->signal.bind(slot))
#define disconnect(sender,signal,slot) ((sender)->signal.unbind(slot))


    template<typename... Args>
    class Slot
    {
    public:
        using OnFunc = std::function<void(Args&&...) >;

        Slot(const OnFunc& func)
                :m_func(func)
        {
            //do nothing
        }

        void exec(Args&&... args)
        {
            m_func(std::forward<Args>(args)...);
        }

        int Get_func_address()
        {
            return (int)(&m_func);
        }

        void Release()
        {
            m_func = nullptr;
        }

    private:
        OnFunc m_func = nullptr;
    };

    template<typename...Args>
    class Signal
    {
    public:
        using SlotPtr = std::shared_ptr<Slot<Args&&...>>;
        using OnFunc = std::function<void(Args&&...)>;

        void bind(const OnFunc& func)
        {
            m_slotvec.push_back(SlotPtr(new Slot<Args&&...>(func)));
        }


        void operator()(Args&&... args)
        {
            for (auto& iter : m_slotvec)
            {
                iter->exec(std::forward<Args>(args)...);
            }
        }

    private:
        std::vector<SlotPtr> m_slotvec;
    };
}


#endif 
