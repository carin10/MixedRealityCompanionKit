// WARNING: Please don't edit this file. It was generated by C++/WinRT v1.0.180821.2

#include "pch.h"
#include "NetworkMediaSink.h"
#include "NetworkMediaSinkStream.h"
#include "RTSchemeHandler.h"
#include "RealtimeMediaPlayer.h"
#include "RealtimeMediaSource.h"
#include "RealtimeServer.h"
#include "Connection.h"
#include "DataBuffer.h"
#include "DataBundleArgs.h"
#include "Listener.h"

int32_t WINRT_CALL WINRT_CanUnloadNow() noexcept
{
#ifdef _WRL_MODULE_H_
    if (!::Microsoft::WRL::Module<::Microsoft::WRL::InProc>::GetModule().Terminate())
    {
        return 1; // S_FALSE
    }
#endif

    if (winrt::get_module_lock())
    {
        return 1; // S_FALSE
    }

    winrt::clear_factory_cache();
    return 0; // S_OK
}

int32_t WINRT_CALL WINRT_GetActivationFactory(void* classId, void** factory) noexcept
{
    try
    {
        *factory = nullptr;
        uint32_t length{};
        wchar_t const* const buffer = WINRT_WindowsGetStringRawBuffer(classId, &length);
        std::wstring_view const name{ buffer, length };

        auto requal = [](std::wstring_view const& left, std::wstring_view const& right) noexcept
        {
            return std::equal(left.rbegin(), left.rend(), right.rbegin(), right.rend());
        };

        if (requal(name, L"RealtimeStreaming.Media.NetworkMediaSink"))
        {
            *factory = winrt::detach_abi(winrt::make<winrt::RealtimeStreaming::Media::factory_implementation::NetworkMediaSink>());
            return 0;
        }

        if (requal(name, L"RealtimeStreaming.Media.NetworkMediaSinkStream"))
        {
            *factory = winrt::detach_abi(winrt::make<winrt::RealtimeStreaming::Media::factory_implementation::NetworkMediaSinkStream>());
            return 0;
        }

        if (requal(name, L"RealtimeStreaming.Media.RTSchemeHandler"))
        {
            *factory = winrt::detach_abi(winrt::make<winrt::RealtimeStreaming::Media::factory_implementation::RTSchemeHandler>());
            return 0;
        }

        if (requal(name, L"RealtimeStreaming.Media.RealtimeMediaPlayer"))
        {
            *factory = winrt::detach_abi(winrt::make<winrt::RealtimeStreaming::Media::factory_implementation::RealtimeMediaPlayer>());
            return 0;
        }

        if (requal(name, L"RealtimeStreaming.Media.RealtimeMediaSource"))
        {
            *factory = winrt::detach_abi(winrt::make<winrt::RealtimeStreaming::Media::factory_implementation::RealtimeMediaSource>());
            return 0;
        }

        if (requal(name, L"RealtimeStreaming.Media.RealtimeServer"))
        {
            *factory = winrt::detach_abi(winrt::make<winrt::RealtimeStreaming::Media::factory_implementation::RealtimeServer>());
            return 0;
        }

        if (requal(name, L"RealtimeStreaming.Network.Connection"))
        {
            *factory = winrt::detach_abi(winrt::make<winrt::RealtimeStreaming::Network::factory_implementation::Connection>());
            return 0;
        }

        if (requal(name, L"RealtimeStreaming.Network.DataBuffer"))
        {
            *factory = winrt::detach_abi(winrt::make<winrt::RealtimeStreaming::Network::factory_implementation::DataBuffer>());
            return 0;
        }

        if (requal(name, L"RealtimeStreaming.Network.DataBundleArgs"))
        {
            *factory = winrt::detach_abi(winrt::make<winrt::RealtimeStreaming::Network::factory_implementation::DataBundleArgs>());
            return 0;
        }

        if (requal(name, L"RealtimeStreaming.Network.Listener"))
        {
            *factory = winrt::detach_abi(winrt::make<winrt::RealtimeStreaming::Network::factory_implementation::Listener>());
            return 0;
        }

#ifdef _WRL_MODULE_H_
        return ::Microsoft::WRL::Module<::Microsoft::WRL::InProc>::GetModule().GetActivationFactory(static_cast<HSTRING>(classId), reinterpret_cast<::IActivationFactory**>(factory));
#else
        return winrt::hresult_class_not_available(name).to_abi();
#endif
    }
    catch (...) { return winrt::to_hresult(); }
}
