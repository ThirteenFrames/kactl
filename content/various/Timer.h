/**
 * Author: Gemini
 * Date: 2025-11-11
 * License: Unknown
 * Source: own work
 * Description: Runs until close to the time limit. Good for brute forcing solutions. 
 * Status: tested
 */
#pragma once

auto start = chrono::high_resolution_clock::now();
auto timeLimit = chrono::milliseconds(900); // <- set to close to time limit
auto now = chrono::high_resolution_clock::now();
if (now - start >= timeLimit) {
    // <- output answer answer
    exit(0);
}