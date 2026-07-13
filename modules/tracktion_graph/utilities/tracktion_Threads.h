/*
    ,--.                     ,--.     ,--.  ,--.
  ,-'  '-.,--.--.,--,--.,---.|  |,-.,-'  '-.`--' ,---. ,--,--,      Copyright 2024
  '-.  .-'|  .--' ,-.  | .--'|     /'-.  .-',--.| .-. ||      \   Tracktion Software
    |  |  |  |  \ '-'  \ `--.|  \  \  |  |  |  |' '-' '|  ||  |       Corporation
    `---' `--'   `--`--'`---'`--'`--' `---' `--' `---' `--''--'    www.tracktion.com

    Tracktion Engine uses a GPL/commercial licence - see LICENCE.md for details.
*/

#pragma once

namespace tracktion { inline namespace graph
{

/** Changes the thread's priority.

    May return false if for some reason the priority can't be changed.

    @param priority     the new priority, in the range 0 (lowest) to 10 (highest). A priority
                        of 5 is normal.
*/
bool setThreadPriority (std::thread&, int priority);

/** Tries to upgrade the current thread to realtime priority. */
bool tryToUpgradeCurrentThreadToRealtime (const juce::Thread::RealtimeOptions&);

/** LAMA-PATCH: registers the CALLING thread with the Windows MMCSS "Pro Audio" task and returns an opaque
    handle (nullptr on failure). Pass that handle to leaveProAudioMmcss() before the thread exits. Both are
    no-ops returning/ignoring nullptr on non-Windows. Kept here so the Win32/avrt.h include stays out of the
    node-player thread-pool translation unit. */
void* enterProAudioMmcss();
void  leaveProAudioMmcss (void* handle);

}} // namespace tracktion_engine
