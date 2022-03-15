function out = sample_xpcblocks
% <name>_xpcblocks Returns a structure that describes an entry
% to be added to the Simulink browser.
%
%   Each instance of this file returns one library to be added to
%   the browser.  You can have multiple instances of this file, each
%   with its own name, ending in xpcblocks.m.
%
%   Copy this file under a new name, <yourname>xpcblocks.m
%   and fill in the library name in Library and the descriptive
%   text that the Simulink browser will display in Name.
%   For example, if your library is named 'mylib.mdl'
%   you would need:
%
%   out.Library = 'mylib';
%   out.Name    = 'My Super IO Library';
%   out.IsFlat  = 0;
%
%   in a copy of this file that might be named myxpcblocks.m.
%   To avoid collisions between different providers of custom
%   libraries, please select a name that is unique, such as
%   your company name or library name.
%
%   You will need to execute a 'rehash toolbox' after
%   adding your new file to the thirdparty directory
%   before it will be found.
%
%   The routine that calls this function adds the string
%   'xPC Target: ' to Name so that the Simulink browser
%   will show 'xPC Target: My Super IO Library' under the
%   standard xPC Target entry in the browser.
%
%   If both Library and Name are empty strings, then nothing
%   gets displayed for this entry in the Simulink browser.
  
% Copyright 2006 The MathWorks, Inc.
% $Revision: 1.1.6.1 $ $Date: 2006/11/15 15:14:10 $

  out.Library = '';
  out.Name    = '';
  out.IsFlat  = 0;
  