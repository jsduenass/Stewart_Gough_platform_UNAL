function blkStruct = slblocks

%SLBLOCKS Defines the Simulink library block representation
%   for xPC Target third party add on libraries.

%   Copyright 1996-2006 The MathWorks, Inc.
%   $Revision: 1.1.6.2 $  $Date: 2008/11/22 22:18:14 $

  blkStruct(1).Name = '';
  blkStruct(1).OpenFcn = '';
  blkStruct(1).MaskInitialization = '';

  cdir = which( 'mxpcinterrupt.m' );
  basedir = fileparts(cdir);
  searchdir = [basedir,'\thirdpartydrivers\*xpcblocks.m'];
  list = dir( searchdir );
  if length(list) >= 1 
    for idx = 1:length(list)
      [pth, file, ext] = fileparts( list(idx).name );
      try
        Browser(idx) = feval( file );
        % add an xPC Target specific decoration to position this
        % in the list when alphabatized.
        if ~strcmp( Browser(idx).Library, '' )
          Browser(idx).Name = ['xPC Target: ', Browser(idx).Name];
          blkStruct(idx).Name = Browser(idx).Name;
          blkStruct(idx).OpenFcn = Browser(idx).Library;
          blkStruct(idx).MaskInitialization = '';
        end
      catch ME
        msg = sprintf( 'xPC Target: Error ''%s'' while adding third party library from %s', ME.message, file );
        disp( msg );
        disp( 'If the function wasn''t found, did you remember to ''rehash toolbox''?');
      end
    end
  else
    Browser(1).Library = '';
    Browser(1).Name    = '';
    Browser(1).IsFlat  = 0;
  end

  % the scanner for 'simulink' uses Browser(N) in the first element
  % of blkStruct.
  % The scanner for 'simulink3' uses blkStruct(N)
  blkStruct(1).Browser = Browser;
